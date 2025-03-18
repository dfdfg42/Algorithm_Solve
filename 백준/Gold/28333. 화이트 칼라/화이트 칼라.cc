#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 1e9;

// BFS 함수: start에서 시작하여 graph를 따라 각 노드까지의 최단 거리를 계산합니다.
void bfs(int start, const vector<vector<int>>& graph, vector<int>& dist) {
    queue<int> q;
    dist[start] = 0;
    q.push(start);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int nxt : graph[cur]) {
            if (dist[nxt] == INF) { // 아직 방문하지 않은 경우
                dist[nxt] = dist[cur] + 1;
                q.push(nxt);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        
        // 인접 리스트와 역방향 인접 리스트 생성
        vector<vector<int>> adj(N+1), rev(N+1);
        for (int i = 0; i < M; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            rev[v].push_back(u);
        }
        
        // 1번 도시에서 각 도시까지의 최단 거리 계산
        vector<int> dist1(N+1, INF);
        bfs(1, adj, dist1);
        
        // N번 도시에서 각 도시까지(역방향 그래프)를 통한 최단 거리 계산
        vector<int> dist2(N+1, INF);
        bfs(N, rev, dist2);
        
        // 전체 최단 거리는 1번에서 N번까지의 거리
        int shortest = dist1[N];
        vector<int> answer;
        
        // 조건: 1번에서 i까지의 거리와 i에서 N까지의 거리 합이 전체 최단 거리에 해당하면 i는 최단 경로상에 있음
        for (int i = 1; i <= N; i++) {
            if (dist1[i] + dist2[i] == shortest) {
                answer.push_back(i);
            }
        }
        
        // 오름차순 정렬 후 출력 (마지막 공백 제거)
        sort(answer.begin(), answer.end());
        for (size_t i = 0; i < answer.size(); i++) {
            cout << answer[i];
            if (i != answer.size() - 1)
                cout << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
