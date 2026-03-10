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

int N, M ,R;


vector<vector<pair<int,int>>> graph;
vector<vector<int>> dist;
vector<int> item;

void dijkstra(int start) {

	priority_queue<pair<int,int>, vector<pair<int,int>>,greater<>> pq;
	
	dist[start][start] = 0;
	pq.push({ 0,start });

	while (!pq.empty()) {
		int cost = pq.top().first;
		int u = pq.top().second;
		pq.pop();

		if (cost > dist[start][u]) continue;

		for (auto edge : graph[u]) {
			int v = edge.first;
			int w = edge.second;

			if (dist[start][u] + w < dist[start][v]) {
				dist[start][v] = dist[start][u] + w;
				pq.push({ dist[start][v],v });
			}

		}

	}
}

int findMaxItem(int start) {

	int sum = 0;
	for (int i = 1; i <= N; i++) {

		if (dist[start][i] <= M) {
			sum += item[i];
		}

	}
	return sum;

}

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> M >> R;
	
	item.resize(N + 1);
	dist.resize(N + 1,vector<int>(N+1,INT_MAX));

	graph.resize(N + 1);

	for (int i = 1; i <= N; i++) {
		cin >> item[i];
	}


	for (int i = 0; i < R; i++) {
		int u, v , cost;
		cin >> u >> v >> cost;

		graph[u].push_back({ v,cost });
		graph[v].push_back({ u,cost });

	}

	for (int i = 1; i <= N; i++) {
		dijkstra(i);
	}


	int ans = 0;
	for (int i = 1; i <= N; i++) {
		ans = max(ans, findMaxItem(i));
	}
	
	cout << ans << '\n';

	return 0;
}