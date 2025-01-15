#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, S, P;
    cin >> N >> S >> P;

    // 그래프 구성 (트리)
    vector<vector<int>> graph(N + 1);
    for(int i = 1; i < N; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // 1) BFS로 P에서 각 노드까지의 거리 구하기
    vector<int> dist(N + 1, -1);
    queue<int> q;
    dist[P] = 0;
    q.push(P);

    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for(int nxt : graph[now]) {
            if(dist[nxt] == -1) { 
                dist[nxt] = dist[now] + 1;
                q.push(nxt);
            }
        }
    }

    // 2) 지지대(1~S)들의 거리만 모아서 정렬
    vector<int> supportDist;
    supportDist.reserve(S);
    for(int i = 1; i <= S; i++) {
        supportDist.push_back(dist[i]);
    }
    sort(supportDist.begin(), supportDist.end());

    // 3) 가장 가까운 2개 거리: d1, d2
    int d1 = supportDist[0]; 
    int d2 = supportDist[1];

    // 4) 결과 = N - ((d1 + 1) + (d2 + 1) - 1) = N - (d1 + d2 + 1)
    int answer = N - (d1 + d2 + 1);

    cout << answer << "\n";
    return 0;
}
