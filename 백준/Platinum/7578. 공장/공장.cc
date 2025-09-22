#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N_segtree;
vector<long long> tree;

void updateTree(int where, long long value) {
    where += N_segtree;
    tree[where] = value;

    while (where > 1) {
        where >>= 1; 
        tree[where] = tree[where << 1] + tree[where << 1 | 1]; 
    }
}

long long query(int left, int right) {
    long long sum = 0;
    left += N_segtree;
    right += N_segtree;

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

    int N; 
    cin >> N;

    N_segtree = N; 
    tree.resize(2 * N_segtree, 0); 

    vector<int> a_line(N);
    vector<int> b_pos(1000001);

    for (int i = 0; i < N; ++i) {
        cin >> a_line[i];
    }

    for (int i = 0; i < N; ++i) {
        int machine_id;
        cin >> machine_id;
        b_pos[machine_id] = i;
    }

    long long inversion_count = 0;

    for (int i = 0; i < N; ++i) {
        int current_machine_id = a_line[i];
        int b_index = b_pos[current_machine_id];

        if (b_index + 1 <= N - 1) {
            inversion_count += query(b_index + 1, N - 1);
        }

        updateTree(b_index, 1);
    }

    cout << inversion_count << '\n';

    return 0;
}