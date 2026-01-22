#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int n, m;
ll adj[11][11];
bool visited[11];
ll ans = -1; 

void dfs(int node, int depth, ll sum) {
    if (depth == n) {
        if (adj[node][0] != -1) {
            ans = max(ans, sum + adj[node][0]);
        }
        return;
    }

    for (int next = 1; next <= n; next++) {
        if (!visited[next] && adj[node][next] != -1) {
            visited[next] = true;
            dfs(next, depth + 1, sum + adj[node][next]);
            visited[next] = false; 
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    if (!(cin >> n >> m)) return 0;


    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++) adj[i][j] = -1;

    for (int i = 0; i < m; i++) {
        int u, v; ll d;
        cin >> u >> v >> d;
        adj[u][v] = max(adj[u][v], d);
    }

    dfs(0, 0, 0);

    cout << ans << '\n';

    return 0;
}