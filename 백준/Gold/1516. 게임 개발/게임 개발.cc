#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> ans(N + 1);     // 최종 정답 리스트(각 건물 짓는 총 필요 시간)
    vector<int> cost(N + 1);    // 각 건물 짓는 순수 시간
    vector<int> degree(N + 1);  // 진입차수 리스트
    vector<vector<int>> graph(N + 1); // 간선표현 리스트
    queue<int> Q;

    // 입력 처리
    for (int i = 1; i <= N; ++i) {
        cin >> cost[i];
        while (true) {
            int ele;
            cin >> ele;
            if (ele == -1) break;
            graph[ele].push_back(i);
            degree[i]++;
        }
    }

    // 초기에 진입차수가 0인 건물들 넣어주기
    for (int i = 1; i <= N; ++i) {
        if (degree[i] == 0) {
            Q.push(i);
            ans[i] = cost[i];
        }
    }

    // 위상 정렬
    while (!Q.empty()) {
        int now = Q.front();
        Q.pop();
        for (int e : graph[now]) {
            degree[e]--;
            ans[e] = max(ans[e], cost[e] + ans[now]);
            if (degree[e] == 0) {
                Q.push(e);
            }
        }
    }

    // 결과 출력
    for (int i = 1; i <= N; ++i) {
        cout << ans[i] << '\n';
    }

    return 0;
}
