#include<iostream>
#include<vector>
#include<algorithm>
#include <climits>
#include <queue>
#include <string>
#include <map>
using namespace std;
typedef long double ld;
typedef long long ll;

int N, M;

vector<bool> visited;
vector < vector<pair<int, ll>>> graph;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	cin >> N >> M;
	visited.resize(N + 1, false);
	graph.resize(N + 1);

	ll total = 0;
	for (int i = 0; i < M; i++) {
		int u, v, c;
		cin >> u >> v >> c;

		graph[u].push_back({ v,c });
		graph[v].push_back({ u,c });
		total += c;
	}

	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;

	ll ans = 0;
	//비용 ,현재 노드
	pq.push({ 0,1 });

	while (!pq.empty()) {

		ll cost = pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (visited[now]) continue;

		total -= cost;
		visited[now] = true;


		for (auto e : graph[now]) {

			int next = e.first;
			ll nextCost = e.second;

			if (visited[next]) {
				continue;
			}

			pq.push({ nextCost,next });

		}

	}


	//전부 visited true 아니면 연결안됨
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			cout << -1 << '\n';
			return 0;
		}

	}

	cout << total << '\n';

	return 0;
}