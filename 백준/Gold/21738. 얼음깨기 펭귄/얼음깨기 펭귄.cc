#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, s, p;
    cin >> n >> s >> p;

    // 인접 리스트 준비
    vector<vector<int>> graph(n + 1);
    vector<bool> visited(n + 1, false);

    // 간선 입력 (트리 구조)
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // BFS 준비
    queue<pair<int, int>> q;
    q.push({ p, 0 });
    visited[p] = true;

    bool find = false;
    int ans = 0;

    while (!q.empty()) {
        // queue에서 (현재 노드, 거리) 꺼내기
        int now = q.front().first;
        int dist = q.front().second;
        q.pop();

        // 현재 노드에 인접한 노드 탐색
        for (auto next : graph[now]) {
            // 아직 방문하지 않은 경우만
            if (!visited[next]) {
                visited[next] = true;

                // 지지대 노드(번호 <= s) 발견 시 처리
                if (next <= s) {
                    // ans가 0이면 첫 번째 지지대,
                    // 그 뒤면 두 번째 지지대라는 가정으로 ans 계산
                    if (find == false) {
                        ans -= (dist + 1);
                        //cout << "ans :" << ans << '\n';
                        find = true;
                    }
                    else {
                        ans -= (dist + 1);
                        //cout << "ans :" << ans << '\n';
                        // 여기서 BFS 완전히 중단 (문제 아이디어상?)
                        cout << n + ans - 1 << endl;
                        return 0;
                    }
                }
                else {
                    // 일반 노드는 계속 큐에 넣어서 탐색
                    q.push({ next, dist + 1 });
                }
            }
        }
    }




    return 0;
}
