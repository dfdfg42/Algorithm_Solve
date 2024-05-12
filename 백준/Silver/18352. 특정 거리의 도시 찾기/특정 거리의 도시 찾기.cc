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


    vector<int> dist(N + 1, INT_MAX);
    queue<int> q;


    q.push(X);
    dist[X] = 0;  

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int neighbor : graph[now]) {
            if (dist[neighbor] == INT_MAX) { 
                dist[neighbor] = dist[now] + 1;
                q.push(neighbor);
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
}
