#include <iostream>
using namespace std;

int parent[300001];
int enemyArr[300001];

int Find(int x) {
    if (parent[x] != x) 
        parent[x] = Find(parent[x]);
    return parent[x];
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a != b) parent[b] = a;
}

void init(int n) {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        enemyArr[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        init(N);

        bool possible = true;
        while (M--) {
            int x, y;
            cin >> x >> y;
            if (!possible) continue;

            int px = Find(x), py = Find(y);
            // 이미 같은 그룹이면 불가능
            if (px == py) {
                possible = false;
                continue;
            }

            // x의 적과 y를 같은 그룹으로
            if (enemyArr[px] != 0) 
                Union(enemyArr[px], py);
            // y의 적과 x를 같은 그룹으로
            if (enemyArr[py] != 0) 
                Union(enemyArr[py], px);

            // 업데이트 후 대표값 재획득
            px = Find(px);
            py = Find(py);

            // 서로를 적(enemy)으로 지정
            enemyArr[px] = py;
            enemyArr[py] = px;
        }

        cout << (possible ? "YES\n" : "NO\n");
    }
    return 0;
}
