#include <bits/stdc++.h>
using namespace std;
#define MAX 100001
#define LOG 20 // log2(MAX) + 1

vector<int> adj[MAX];
int parent[MAX][LOG];
int depth[MAX];

void dfs(int v, int d, int p) {
    depth[v] = d;
    parent[v][0] = p;
    for (int next : adj[v]) {
        if (next != p) dfs(next, d + 1, v);
    }
}

int lca(int a, int b) {
    if (depth[a] > depth[b]) swap(a, b);
    for (int i = LOG - 1; i >= 0; i--) {
        if (depth[b] - depth[a] >= (1 << i)) {
            b = parent[b][i];
        }
    }
    if (a == b) return a;
    for (int i = LOG - 1; i >= 0; i--) {
        if (parent[a][i] != parent[b][i]) {
            a = parent[a][i];
            b = parent[b][i];
        }
    }
    return parent[a][0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n;
    
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(1, 0, 0);
    
    for (int i = 1; i < LOG; i++) {
        for (int j = 1; j <= n; j++) {
            parent[j][i] = parent[parent[j][i - 1]][i - 1];
        }
    }
    
    cin >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }
    
    return 0;
}
