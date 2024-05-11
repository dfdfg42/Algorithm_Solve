#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N, M;
        cin >> N >> M;
        vector<vector<pair<int, int>>> adj(M);
        for (int i = 0; i < N; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            adj[x].push_back({y, z});
            adj[y].push_back({x, z});
        }

        // 다익스트라 알고리즘
        vector<int> dist(M, INT_MAX);
        vector<int> prev(M, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0}); // 시작점: 한신이
        dist[0] = 0;
        while (!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            if (d > dist[u]) continue;
            for (auto& edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;
                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    prev[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }

        // 결과 출력
        cout << "Case #" << t << ": ";
        if (dist[M-1] == INT_MAX) {
            cout << "-1\n";
        } else {
            vector<int> path;
            for (int cur = M-1; cur != -1; cur = prev[cur]) {
                path.push_back(cur);
            }
            reverse(path.begin(), path.end());
            for (int node : path) {
                cout << node << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
