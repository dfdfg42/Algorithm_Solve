#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

static const int INF = 2100000000;

int v, m;
int j, s;
int dist1[101]; // 지헌이 최단거리
int dist2[101]; // 성하 최단거리


vector<vector<pair<int, int>>> nodes;

void dijkstra(int start, int dist[]) {

    for (int i = 1; i <= v; i++) {
        dist[i] = INF;
    }
    dist[start] = 0;


    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (cost > dist[now]) continue;

        // now 정점에서 연결된 간선 확인
        for (auto& edge : nodes[now]) {
            int nxt = edge.first;
            int nxt_cost = cost + edge.second;
            if (nxt_cost < dist[nxt]) {
                dist[nxt] = nxt_cost;
                pq.push({ nxt_cost, nxt });
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> v >> m;
    nodes.resize(v + 1);

    // 간선 입력
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        nodes[a].push_back({ b, c });
        nodes[b].push_back({ a, c });
    }
    cin >> j >> s;


    dijkstra(j, dist1);
    dijkstra(s, dist2);

    int JS_distance = INF;
    for (int i = 1; i <= v; i++) {
        if (i == j || i == s) continue; 
        int sum = dist1[i] + dist2[i];
        if (sum < JS_distance) {
            JS_distance = sum;
        }
    }


    int Point = -1;
    int best_J_dis = INF; 

    for (int i = v; i >= 1; i--) {
        if (i == j || i == s) continue;
        if (dist1[i] + dist2[i] != JS_distance) continue;
        if (dist1[i] > dist2[i]) continue;

        if (dist1[i] <= best_J_dis) {
            best_J_dis = dist1[i];
            Point = i;
        }
    }

    if (Point == -1) cout << -1 << "\n";
    else cout << Point << "\n";

    return 0;
}