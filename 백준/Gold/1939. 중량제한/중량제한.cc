#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int N, M,s ,e;
int maxCost;

vector < vector<pair<int, int>>> graph;


bool bfs(int cost) {

	vector<int> visited(N + 1, false);

	visited[s] = true;

	queue<int> q;
	q.push(s);

	while (!q.empty()) {

		int now = q.front();
		q.pop();

		for (auto a : graph[now]) {

			int next = a.first;
			int nextCost = a.second;

			if (!visited[next] && nextCost >= cost) {
				q.push(next);
				visited[next] = true;
			}

		}

	}

	if (visited[e]) return true;
	else return false;

}

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	maxCost = 0;
	graph.resize(N + 1);
	for (int i = 0; i < M; i++) {
		int u, v, c;
		cin >> u >> v >> c;

		maxCost = max(c, maxCost);

		graph[u].push_back({ v,c });
		graph[v].push_back({ u,c });
	}
	
	cin >> s >> e;


	//이분탐색으로 용량 몇으로 할지 정함
	int l = 0, r = maxCost;
	int ans = 0;

	while (l <= r) {
		int mid = (l + r) / 2;

		//bfs로 s에서 e 까지 갈 수 있는지 고름
		if (bfs(mid)) {
			ans = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}

	}

	
	cout << ans << '\n';


	return 0;
}