#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <iomanip>
#include <tuple>
#include <sstream>
#include <map>
using namespace std;

#define mod 1'000'000'007

vector<long long> arr;
vector<long long> tree;

// 세그먼트 트리 초기화 함수
long long init(int start, int end, int index) {
    if (start == end) {
        tree[index] = arr[start];
        return tree[index];
    }
    int mid = (start + end) / 2;

    tree[index] = (init(start, mid, index * 2) * init(mid + 1, end, index * 2 + 1)) % mod;
    return tree[index];
}

// 구간 곱 구하는 함수
long long interval_product(int start, int end, int index, int left, int right) {
    if (left > end || right < start) {
        return 1;
    }

    if (left <= start && end <= right) {
        return tree[index];
    }

    int mid = (start + end) / 2;
    return (interval_product(start, mid, index * 2, left, right) * interval_product(mid + 1, end, index * 2 + 1, left, right)) % mod;
}

// 세그먼트 트리 업데이트 함수
void update(int start, int end, int index, int what, long long newValue) {
    if (what < start || what > end) {
        return;
    }

    if (start == end) {
        tree[index] = newValue;
        return;
    }

    int mid = (start + end) / 2;
    update(start, mid, index * 2, what, newValue);
    update(mid + 1, end, index * 2 + 1, what, newValue);
    tree[index] = (tree[index * 2] * tree[index * 2 + 1]) % mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;
    arr.resize(N + 1);
    tree.resize(4 * N);

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    init(1, N, 1);

    for (int i = 0; i < M + K; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        if (a == 1) {
            update(1, N, 1, b, c);
            arr[b] = c;
        }
        else {
            cout << interval_product(1, N, 1, b, c) << '\n';
        }
    }

    return 0;
}
