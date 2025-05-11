#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)9e18;

struct Edge { int to; int w; };

vector<ll> dijkstra(int src, const vector<vector<Edge>>& G) {
    int n = G.size();
    vector<ll> dist(n, INF);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
        auto [d,u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto &e : G[u]) {
            ll nd = d + e.w;
            if (nd < dist[e.to]) {
                dist[e.to] = nd;
                pq.push({nd, e.to});
            }
        }
    }
    return dist;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<Edge>> graph(N+1);
    for(int i = 0; i < M; i++){
        int u, v, c;
        cin >> u >> v >> c;
        graph[u].push_back({v, c});
        graph[v].push_back({u, c});
    }

    vector<int> e(N+1);
    for(int i = 1; i <= N; i++){
        cin >> e[i];  // e[i] == -1 이면 엘리베이터 없음
    }

    // 1번 방에서 모든 방까지, N번 방에서 모든 방까지
    auto dist1 = dijkstra(1, graph);
    auto dist2 = dijkstra(N, graph);

    ll answer = INF;
    // 엘리베이터가 있는 방 i에 대해 후보 계산
    for(int i = 1; i <= N; i++){
        if (e[i] == -1) continue;
        if (dist1[i] == INF || dist2[i] == INF) continue;
        // 1층 → i방 복도 + i방 엘리베이터로 1→K층 + K층→N방 복도
        ll cost = dist1[i]
                + (ll)e[i] * (K - 1)
                + dist2[i];
        answer = min(answer, cost);
    }

    if (answer == INF) cout << -1 << "\n";
    else             cout << answer << "\n";

    return 0;
}
