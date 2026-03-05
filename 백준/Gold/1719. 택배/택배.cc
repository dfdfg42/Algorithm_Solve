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

//첫번째 방문한 노드 기억하기
vector<vector<pair<int,int>>> dist;

void dijkstra(int start) {

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater< >> pq;

	dist[start][start].first = 0;
	pq.push({ 0,start });

	while (!pq.empty()) {
		int cost = pq.top().first;
		int u = pq.top().second;
		pq.pop();

		if (cost > dist[start][u].first) continue;

		for (auto edge : graph[u]) {

			int v = edge.first;
			int weight = edge.second;

			if (dist[start][u].first + weight < dist[start][v].first) {
				dist[start][v].first = dist[start][u].first + weight;
				//첫번째 방문이면 갱신
				if (u == start) {
					dist[start][v].second = v;
				}
				else {
					dist[start][v].second = dist[start][u].second;
				}
				
				pq.push({ dist[start][v].first,v });
			}

		}

	}

}

int main()
{
	
	cin >> N >> M;
	
	graph.resize(N + 1);
	dist.resize(N + 1, vector<pair<int, int>>(N + 1, { INT_MAX,0 }));

	for (int i = 0; i < M; i++) {

		int u, v, t;
		cin >> u >> v >> t;

		graph[u].push_back({ v,t });
		graph[v].push_back({ u,t });

	}

	for (int i = 1; i <= N; i++) {
		dijkstra(i);
	}


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) {
				cout << "- ";
			}
			else {
				cout << dist[i][j].second << " ";
			}
		}
		cout << '\n';
	}


	return 0;
}