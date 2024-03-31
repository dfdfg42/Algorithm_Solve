#include <iostream>
#include <vector>
using namespace std;

vector<long long> tree; // 세그먼트 트리는 long long 타입을 사용하여 오버플로우 방지
int N, M;

// 세그먼트 트리 초기화 함수는 필요 없음

// 구간 합 쿼리 함수
long long interval_sum(int index, int start, int end, int left, int right) {
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[index];
    int mid = (start + end) / 2;
    return interval_sum(index * 2, start, mid, left, right) + interval_sum(index * 2 + 1, mid + 1, end, left, right);
}

// 세그먼트 트리 업데이트 함수
void update(int index, int start, int end, int target, long long diff) {
    if (target < start || target > end) return;
    tree[index] += diff;
    if (start != end) {
        int mid = (start + end) / 2;
        update(index * 2, start, mid, target, diff);
        update(index * 2 + 1, mid + 1, end, target, diff);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    tree.resize(4 * N); 

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            // 1 p x: 생후 p일에 x를 추가한다.
            update(1, 1, N, b, c);
        }
        else {
            // 2 p q: 생후 p일부터 q일까지 변화한 양을 출력한다.
            cout << interval_sum(1, 1, N, b, c) << '\n';
        }
    }
    return 0;
}
