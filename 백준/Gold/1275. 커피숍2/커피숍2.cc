#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> tree;
vector<long long> a;
int N, Q;

// 세그먼트 트리 구축
void build() {
    for (int i = 0; i < N; ++i) {
        tree[N + i] = a[i];
    }
    for (int i = N - 1; i > 0; --i) {
        tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }
}

// 세그먼트 트리의 특정 위치 값 업데이트
void updateTree(int where, long long value) {
    where += N;
    tree[where] = value;

    while (where > 1) {
        where >>= 1;
        tree[where] = tree[where << 1] + tree[where << 1 | 1];
    }
}

// 세그먼트 트리 구간 합 쿼리
long long query(int left, int right) {
    long long sum = 0;
    left += N;
    right += N;

    while (left <= right) {
        if (left & 1) sum += tree[left++];
        if (!(right & 1)) sum += tree[right--];
        left >>= 1;
        right >>= 1;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> Q;
    a.resize(N);
    tree.resize(2 * N);

    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    build();

    for (int i = 0; i < Q; ++i) {
        int x, y, a_idx;
        long long b;
        cin >> x >> y >> a_idx >> b;
        if (x > y) swap(x, y);
        cout << query(x - 1, y - 1) << '\n';
        updateTree(a_idx - 1, b);
    }

    return 0;
}
