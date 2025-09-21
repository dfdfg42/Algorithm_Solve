#include <iostream>
#include <vector>

using namespace std;

const int MAX_TASTE = 1000000;
vector<long long> tree;

void update(int node, int start, int end, int index, int diff) {
    if (index < start || index > end) {
        return;
    }
    tree[node] += diff;
    if (start != end) {
        int mid = (start + end) / 2;
        update(node * 2, start, mid, index, diff);
        update(node * 2 + 1, mid + 1, end, index, diff);
    }
}


int query(int node, int start, int end, int k) {
    if (start == end) {
        return start;
    }

    int mid = (start + end) / 2;
    long long left_child_count = tree[node * 2];

    if (k <= left_child_count) {
        return query(node * 2, start, mid, k);
    }

    else {
        return query(node * 2 + 1, mid + 1, end, k - left_child_count);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    tree.resize(4 * MAX_TASTE);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int A;
        cin >> A;

        if (A == 1) { 
            int B;
            cin >> B;
            int taste = query(1, 1, MAX_TASTE, B);
            cout << taste << '\n';
 
            update(1, 1, MAX_TASTE, taste, -1);
        }
        else { 
            int B, C;
            cin >> B >> C;

            update(1, 1, MAX_TASTE, B, C);
        }
    }

    return 0;
}
