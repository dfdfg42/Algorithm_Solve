#include <iostream>
#include <vector>
using namespace std;

#define MAX 500000

int parent[MAX]; // 부모 노드를 저장하는 배열

int Find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = Find(parent[x]); // 경로 압축
}

void Union(int x, int y) { // 함수 이름을 `Union`으로 변경
    x = Find(x);
    y = Find(y);

    if (x != y) {
        if (x < y)
            parent[y] = x;
        else
            parent[x] = y;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        parent[i] = i; // 각 노드의 부모를 자기 자신으로 초기화
    }

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;

        // 이미 같은 집합에 속해 있다면, 사이클이 형성됨
        if (Find(a) == Find(b)) {
            cout << i; // 사이클이 처음으로 만들어진 차례의 번호 출력
            return 0;
        }

        Union(a, b); // 두 노드를 하나의 집합으로 합치기
    }

    cout << "0"; // 모든 차례를 처리한 후에도 사이클이 형성되지 않았다면 0 출력
    return 0;
}
