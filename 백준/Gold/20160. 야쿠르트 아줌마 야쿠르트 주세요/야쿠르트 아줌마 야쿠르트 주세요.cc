#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

typedef long long ll;
const int INF = INT_MAX;

int v, e;
vector<vector<pair<int,int>>> graph;
vector<pair<int,ll>> way;   
vector<int> dist_arr;

void dijkstra(int start) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push(make_pair(0, start));
    while (!pq.empty()) {
        pair<int,int> top = pq.top();
        int cost = top.first;
        int u = top.second;
        pq.pop();
        if (cost > dist_arr[u]) continue;
        for (size_t i = 0; i < graph[u].size(); ++i) {
            pair<int,int> edge = graph[u][i];
            int nxt = edge.first;
            int w = edge.second;
            if (dist_arr[nxt] > cost + w) {
                dist_arr[nxt] = cost + w;
                pq.push(make_pair(dist_arr[nxt], nxt));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> v >> e;
    graph.assign(v+1, vector<pair<int,int>>());
    dist_arr.assign(v+1, INF);

    for (int i = 0; i < e; ++i) {
        int u, v2, w;
        cin >> u >> v2 >> w;
        graph[u].push_back(make_pair(v2, w));
        graph[v2].push_back(make_pair(u, w));
    }

    way.assign(11, make_pair(0, -1LL));
    for (int i = 1; i <= 10; ++i) {
        cin >> way[i].first;
    }
    int me;
    cin >> me;

    way[1].second = 0LL;
    for (int idx = 1; idx < 10;) {
        dist_arr.assign(v+1, INF);
        dist_arr[ way[idx].first ] = 0;
        dijkstra(way[idx].first);
        int next = idx + 1;
        while (next <= 10 && dist_arr[ way[next].first ] == INF) next++;
        if (next > 10) break;
        way[next].second = way[idx].second + dist_arr[ way[next].first ];
        idx = next;
    }


    dist_arr.assign(v+1, INF);
    dist_arr[me] = 0;
    dijkstra(me);


    int answer = INT_MAX;
    for (int k = 1; k <= 10; ++k) {
        int station = way[k].first;
        if (dist_arr[station] < INF && dist_arr[station] <= way[k].second) {
            answer = min(answer, station);
        }
    }

    if (answer == INT_MAX) cout << -1;
    else cout << answer;
    return 0;
}