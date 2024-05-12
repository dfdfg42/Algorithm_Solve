#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K, X;

    cin >> N >> M >> K >> X;

    vector<vector<int>> graph(N+1);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
    }


    vector<bool> visited(N+1,false);
    vector<int> dist(N+1, INT_MAX);
    queue<int> q;

    q.push(X);
    visited[X] = true;
    dist[X] = 0;

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (auto edge : graph[now]) {

            if (!visited[edge]) {
                visited[edge] = true;
                dist[edge] = dist[now] + 1;
                q.push(edge);

            }
        }
    }

    vector<int> result;
    for (int i = 1; i <= N; i++) {
        if (dist[i] == K) {
            result.push_back(i);
        }
    }


    if (result.empty()) {
        cout << "-1\n";
    }
    else {
        sort(result.begin(), result.end());
        for (int city : result) {
            cout << city << '\n';
        }
    }

    return 0;
}
