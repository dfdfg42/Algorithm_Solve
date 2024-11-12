#include <iostream>
#include <vector>

using namespace std;

vector<vector<pair<int, int>>> graph;
vector<bool> visited;
int n, q;

int dfs(int i, int d, int value) {
    if (i == d) {
        return value;
    }

    visited[i] = true;

    for (auto edge : graph[i]) {
        int next = edge.first;
        int weight = edge.second;

        if (!visited[next]) {
            int result = dfs(next, d, value + weight);
            if (result != -1) {
                return result;
            }
        }
    }

    return -1;
}

int main() {
    cin >> n >> q;
    visited.resize(n + 1);
    graph.resize(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].push_back({ b, c });
        graph[b].push_back({ a, c });
    }

    for (int i = 0; i < q; i++) {
        int s, d;
        cin >> s >> d;
        visited.assign(n + 1, false);
        int result = dfs(s, d, 0);

        cout << result << '\n';
    }

    return 0;
}
