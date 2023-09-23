#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 2e9;
int d[30000];
vector<pair<int, int>> adj[30000];

int v, e, st,goal;

void dijkstra(int st) {
    fill(d, d + v + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    d[st] = 0;
    pq.push({ d[st],st });
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if (d[cur.second] != cur.first)continue;
        for (auto nxt : adj[cur.second]) {
            if (d[nxt.second] <= d[cur.second] + nxt.first) continue;
            d[nxt.second] = d[cur.second] + nxt.first;
            pq.push({ d[nxt.second],nxt.second });
        }
    }


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> v >> e ;
    while (e--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ w,v });
    }
    cin >> st >> goal;

    dijkstra(st);

    cout << d[goal];

    return 0;
}
