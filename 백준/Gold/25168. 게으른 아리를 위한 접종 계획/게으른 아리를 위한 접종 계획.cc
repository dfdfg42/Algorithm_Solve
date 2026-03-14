#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<vector<pair<int, int>>> graph(N + 1);
	vector<int> indegree(N + 1, 0);
	vector<long long> dp(N + 1, 1);

	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ v, w });
		indegree[v]++;
	}

	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) q.push(i);
	}

	long long ans = 1;

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		ans = max(ans, dp[cur]);

		for (auto[next, w] : graph[cur]) {
			long long vaccineDay;
			if (w <= 6) {
				vaccineDay = dp[cur] + w;      // 유효기간 내
			}
			else {
				vaccineDay = dp[cur] + w + 1;  // 재접종 후 다음날
			}
			dp[next] = max(dp[next], vaccineDay);

			indegree[next]--;
			if (indegree[next] == 0) q.push(next);
		}
	}

	cout << ans << '\n';
	return 0;
}