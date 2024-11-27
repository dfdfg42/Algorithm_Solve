#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

const long long INF = 1e18; // 무한대를 크게 설정

int n, m; // n: 노드 개수, m: 간선 개수

vector<long long> dijkstra(int start, int n, vector<vector<pair<int, int>>>& graph, int M) {
    vector<long long> dist(n, INF); // 최단 거리 테이블을 무한으로 초기화
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

    dist[start] = 0;
    pq.push({ 0, start }); // 시작 노드로 가기 위한 비용은 0으로 설정

    while (!pq.empty()) {
        long long time = pq.top().first;    // 현재 노드까지의 비용
        int u = pq.top().second;      // 현재 노드
        pq.pop();

        if (time > dist[u]) continue; // 이미 처리된 노드라면 무시

        for (auto& edge : graph[u]) {
            int v = edge.first;       // 인접 노드
            int i = edge.second;      // 횡단보도 신호의 초기 오프셋

            long long ntime;
            if (time <= i) {
                ntime = i;
            }
            else {
                long long delta = time - i;
                long long k = (delta + M - 1) / M;
                ntime = i + k * M;
            }

            long long arrival_time = ntime + 1; // 횡단보도를 건너는 데 1분 소요

            if (arrival_time < dist[v]) { // 더 짧은 경로 발견 시 업데이트
                dist[v] = arrival_time;
                pq.push({ dist[v], v });
            }
        }
    }

    return dist; // 각 노드로의 최단 거리 반환
}

int main() {

    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u - 1].push_back({ v - 1, i });
        graph[v - 1].push_back({ u - 1, i });
    }

    vector<long long> shortest_paths = dijkstra(0, n, graph, m);

    if (shortest_paths[n - 1] == INF)
        cout << -1 << endl; // 도달할 수 없는 경우
    else
        cout << shortest_paths[n - 1] << endl; // 1번 지역에서 N번 지역까지의 최소 시간

    return 0;
}
