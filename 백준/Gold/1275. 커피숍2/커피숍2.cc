#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> tree;
vector<long long> a;
int N, Q, howmany;

// Function to build the segment tree
void build() {
    for (int i = 0; i < N; ++i) {
        tree[howmany + i] = a[i];
    }
    for (int i = howmany - 1; i > 0; --i) {
        tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }
}

// Function to update a value in the segment tree
void updateTree(int where, long long value) {
    where += howmany;
    tree[where] = value;

    while (where > 1) {
        where >>= 1;
        tree[where] = tree[where << 1] + tree[where << 1 | 1];
    }
}

// Function to query the sum in the range [left, right]
long long query(int left, int right) {
    long long sum = 0;
    left += howmany;
    right += howmany;

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
    howmany = 1;
    while (howmany < N) howmany <<= 1;
    tree.resize(2 * howmany);

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
