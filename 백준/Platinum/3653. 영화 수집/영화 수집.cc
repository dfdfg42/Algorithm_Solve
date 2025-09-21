#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


vector<int> tree;
vector<int> pos;
int total_size; 
void updateTree(int where, int value) {
    where += total_size;
    tree[where] += value;

    while (where > 1) {
        where >>= 1; 
        tree[where] = tree[where << 1] + tree[where << 1 | 1]; 
    }
}

int query(int left, int right) {
    int sum = 0;

    left += total_size;
    right += total_size;

    while (left <= right) {
        if (left & 1) sum += tree[left++];
        if (!(right & 1)) sum += tree[right--];
        left >>= 1;
        right >>= 1;
    }
    return sum;
}


void solve() {
    int n, m;
    cin >> n >> m;

    total_size = n + m;
    tree.assign(2 * total_size, 0);
    pos.assign(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        pos[i] = m + i - 1;
        updateTree(pos[i], 1); 
    }

    int top_idx = m - 1; 

    for (int i = 0; i < m; ++i) {
        int movie_num;
        cin >> movie_num;

        int current_pos = pos[movie_num];

        cout << query(0, current_pos - 1) << " ";

        updateTree(current_pos, -1);
        updateTree(top_idx, 1);

        pos[movie_num] = top_idx;

        top_idx--;
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
