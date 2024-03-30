#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();
vector<pair<int, int>> tree;
vector<int> arr;

// 세그먼트 트리 초기화 함수: (최솟값, 인덱스) 저장
pair<int, int> init(int start, int end, int node) {
    if (start == end) return tree[node] = {arr[start], start};

    int mid = (start + end) / 2;
    pair<int, int> leftNode = init(start, mid, node * 2);
    pair<int, int> rightNode = init(mid + 1, end, node * 2 + 1);

    return tree[node] = (leftNode.first <= rightNode.first ? leftNode : rightNode);
}

// 최솟값과 그 인덱스를 찾는 함수
pair<int, int> query(int start, int end, int node, int left, int right) {
    if (left > end || right < start) return {INF, -1};
    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    pair<int, int> leftQuery = query(start, mid, node * 2, left, right);
    pair<int, int> rightQuery = query(mid + 1, end, node * 2 + 1, left, right);

    return (leftQuery.first <= rightQuery.first ? leftQuery : rightQuery);
}

// 세그먼트 트리 업데이트 함수
void update(int start, int end, int node, int index, int newValue) {
    if (index < start || index > end) return;
    if (start == end) {
        tree[node] = {newValue, index};
        return;
    }

    int mid = (start + end) / 2;
    update(start, mid, node * 2, index, newValue);
    update(mid + 1, end, node * 2 + 1, index, newValue);

    tree[node] = (tree[node * 2].first <= tree[node * 2 + 1].first ? tree[node * 2] : tree[node * 2 + 1]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    arr.resize(N + 1);
    tree.resize(4 * N);

    for (int i = 1; i <= N; i++) cin >> arr[i];

    init(1, N, 1);

    int M;
    cin >> M;
    while (M--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            arr[b] = c;
            update(1, N, 1, b, c);
        } else {
            pair<int, int> result = query(1, N, 1, b, c);
            cout << result.second << '\n'; // 인덱스 출력
        }
    }
    return 0;
}
