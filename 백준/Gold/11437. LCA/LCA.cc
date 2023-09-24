#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAX = 50001;
const int LOG = 16; // log2(50000)의 정수 부분은 15.6이므로 16으로 설정

int n, m;
vector<int> adj[MAX];
int parent[MAX][LOG];
int depth[MAX];

void dfs(int v, int p, int d) {
    depth[v] = d;
    parent[v][0] = p;
    
    for(int next : adj[v]) {
        if(next != p) dfs(next, v, d + 1);
    }
}

void setParent() {
    for(int j = 1; j < LOG; j++) {
        for(int i = 1; i <= n; i++) {
            parent[i][j] = parent[parent[i][j-1]][j-1];
        }
    }
}

int LCA(int a, int b) {
    if(depth[a] > depth[b]) swap(a, b);
    
    for(int i = LOG - 1; i >= 0; i--) {
        if(depth[b] - depth[a] >= (1 << i)) {
            b = parent[b][i];
        }
    }
    
    if(a == b) return a;
    
    for(int i = LOG - 1; i >= 0; i--) {
        if(parent[a][i] != parent[b][i]) {
            a = parent[a][i];
            b = parent[b][i];
        }
    }
    
    return parent[a][0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(1, 0, 0);
    setParent();
    
    cin >> m;
    
    while(m--) {
        int a, b;
        cin >> a >> b;
        cout << LCA(a, b) << '\n';
    }
    
    return 0;
}
