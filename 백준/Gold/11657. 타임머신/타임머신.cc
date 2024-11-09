#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

const long long INF = 1e18; // INF를 충분히 큰 값으로 설정

int n, m;
vector<tuple<int, int, int>> edges;
vector<long long> dist;

bool bellmanFord(int start) {
    dist[start] = 0;

    // 모든 간선을 최대 (V-1)번 반복
    for (int i = 1; i <= n - 1; i++) {
        for (auto& edge : edges) {
            int u, v, weight;
            tie(u, v, weight) = edge;

            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // 음수 사이클 체크
    for (auto& edge : edges) {
        int u, v, weight;
        tie(u, v, weight) = edge;

        if (dist[u] != INF && dist[u] + weight < dist[v]) {
            cout << -1 << '\n';
            return false; // 음수 사이클이 존재
        }
    }

    return true; // 음수 사이클이 없음
}

int main() {
    cin >> n >> m;

    edges.resize(m);
    dist.resize(n + 1, INF);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = make_tuple(u, v, w);
    }

    int start = 1; // 시작 노드를 1로 설정

    if (bellmanFord(start)) {
        for (int i = 2; i <= n; i++) {
            if (dist[i] == INF) {
                cout << -1 << '\n';
            } else {
                cout << dist[i] << '\n';
            }
        }
    }

    return 0;
}
