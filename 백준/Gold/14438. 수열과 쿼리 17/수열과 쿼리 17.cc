#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<long long> tree;
vector<long long> a;
int N, Q;

void build() {
    for (int i = 0; i < N; ++i) {
        tree[N + i] = (i<N ? a[i] : LLONG_MAX);
    }
    for (int i = N - 1; i > 0; --i) {
        tree[i] = min(tree[i << 1] ,tree[i << 1 | 1]);
    }
}

void updateTree(int where, long long value) {
    where += N;
    tree[where] = value;

    while (where > 1) {
        where >>= 1;
        tree[where] = min( tree[where << 1] ,tree[where << 1 | 1]);
    }
}

long long query(int left, int right) {
    long long minVal = LLONG_MAX;
    left += N;
    right += N;

    while (left <= right) {
        if (left & 1) minVal = min(minVal,tree[left++]);
        if (!(right & 1)) minVal = min(minVal,tree[right--]);
        left >>= 1;
        right >>= 1;
    }
    return minVal;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    a.resize(N);
    tree.resize(2 * N);

    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    build();

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int input;
        cin >> input;

        if (input == 1) {
            int a, b;
            cin >> a >> b;
            updateTree(a-1, b);
        }
        else if (input == 2) {
            int a,b; 
            cin >> a >> b;
            cout << query(a-1 ,b-1) <<'\n';
        }
    }

    

    return 0;
}