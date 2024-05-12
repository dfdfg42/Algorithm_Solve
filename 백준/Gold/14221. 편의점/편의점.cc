#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<pii>> graph(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({ b, c });
        graph[b].push_back({ a, c });
    }

    int p, q;
    cin >> p >> q;
    vector<int> houses(p);
    vector<int> convenience(q);
    vector<int> min_dist(n + 1, INT_MAX);

    for (int i = 0; i < p; i++) {
        cin >> houses[i];
    }

    for (int i = 0; i < q; i++) {
        cin >> convenience[i];
    }

    // 다중 출발점 다익스트라
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int start : convenience) {
        pq.push({ 0, start });
        min_dist[start] = 0;
    }

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > min_dist[u]) continue;

        for (auto& edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;
            if (min_dist[v] > min_dist[u] + w) {
                min_dist[v] = min_dist[u] + w;
                pq.push({ min_dist[v], v });
            }
        }
    }

    // 최소 거리를 가진 집 후보 찾기
    int min_index = -1;
    int min_value = INT_MAX;
    for (int house : houses) {
        if (min_dist[house] < min_value) {
            min_value = min_dist[house];
            min_index = house;
        }
        else if (min_dist[house] == min_value) {
            min_index = min(min_index, house);
        }
    }

    cout << min_index << '\n';

    return 0;
}
