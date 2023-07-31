#include <iostream>
#include <vector>
using namespace std;
long long N, M, K, a, b, c, h = 1;
vector <long long>tree, num;
void update(int idx, long long value) {
    idx += h;
    tree[idx] = value;
    while (idx > 1) {
        idx /= 2;
        tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
    }
}
long long query(int L, int R, int node, int nodeL, int nodeR) {
    if (L <= nodeL && nodeR <= R) return tree[node];
    if (nodeR < L || R < nodeL) return 0;
    int mid = (nodeL + nodeR) / 2;
    return query(L, R, node * 2, nodeL, mid) + query(L, R, node * 2 + 1, mid + 1,nodeR);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> K;
    while (N > h) h <<= 1;
    tree.resize(2 * h);
    num.resize(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> num[i];
        update(i, num[i]);
    }
    for (int i = 0; i < M + K; i++) {
        cin >> a >> b >> c;
        if (a == 1) update(b - 1, c);
        else cout << query(b, c, 1, 1, h) << '\n';
    }

    
}