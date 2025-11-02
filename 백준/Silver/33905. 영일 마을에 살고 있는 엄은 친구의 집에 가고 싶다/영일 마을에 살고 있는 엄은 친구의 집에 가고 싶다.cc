#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

int n, m, k;

vector<vector<int>> graph;
set<int> cant;

vector<bool> visited;

void dfs(int index) {

    for (auto a : graph[index]) {

        if (!visited[a] && cant.find(a) == cant.end()) {
            //cout << "visited  : " << a << '\n';
            visited[a] = true;
            dfs(a);
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;
    graph.resize(n+2);
    visited.resize(n+2,false);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 0; i < k; i++) {
        int input;
        cin >> input;
        cant.insert(input);
    }

    visited[1] = true;
    dfs(1);

    int ans = 0;
    for (int i = 2; i <= n+1; i++) {
        if (visited[i]) ans++;
    }
    cout << ans << '\n';
    
    return 0;
}