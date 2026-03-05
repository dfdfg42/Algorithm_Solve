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

int N, M, X;

vector<vector<pair<int,int>>> graph;

vector<vector<int>> dist;

void dijkstra(int start) {

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater< >> pq;

	dist[start][start] = 0;
	pq.push({ 0,start });

	while (!pq.empty()) {
		int cost = pq.top().first;
		int u = pq.top().second;
		pq.pop();

		if (cost > dist[start][u]) continue;

		for (auto edge : graph[u]) {

			int v = edge.first;
			int weight = edge.second;

			if (dist[start][u] + weight < dist[start][v]) {
				dist[start][v] = dist[start][u] + weight;
				pq.push({ dist[start][v],v });
			}

		}

	}

}

int main()
{
	
	cin >> N >> M >> X;
	
	graph.resize(N + 1);
	dist.resize(N + 1,vector<int>(N+1,INT_MAX));

	for (int i = 0; i < M; i++) {

		int u, v, t;
		cin >> u >> v >> t;

		graph[u].push_back({ v,t });

	}

	for (int i = 1; i <= N; i++) {
		dijkstra(i);
	}

	int ans = 0;

	for (int i = 1; i <= N; i++) {


		if (dist[i][X] != INT_MAX && dist[X][i] != INT_MAX) {
			ans = max(ans, dist[i][X] + dist[X][i]);
		}
		

	}

	cout << ans << '\n';

	return 0;
}