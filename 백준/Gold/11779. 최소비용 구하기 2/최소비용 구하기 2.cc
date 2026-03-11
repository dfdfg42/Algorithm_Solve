#include<iostream>
#include<vector>
#include<algorithm>
#include <climits>
#include <queue>
#include <string>

using namespace std;

int N, M, s, e;


vector<int> dist;
vector<vector<pair<int,int>>> graph;
vector<int> prevNode;


void dijkstra(int start) {


	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

	dist[start] = 0;
	pq.push({ 0,start });

	while (!pq.empty()) {


		int cost = pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (dist[now] < cost) continue;

		for (auto next : graph[now]) {

			int nextNode = next.first;
			int w = next.second;

			if (dist[nextNode] > dist[now] + w) {
				prevNode[nextNode] = now;
				dist[nextNode] = dist[now] + w;
				pq.push({ dist[nextNode],nextNode });

			}


		}

	}



}

int main()
{
	cin >> N >> M;

	graph.resize(N + 1);
	dist.resize( N + 1, 2'000'000'000);
	prevNode.resize(N + 1, 0);

	for (int i = 0; i < M; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		graph[u].push_back({ v,c });

	}

	cin >> s >> e;

	dijkstra(s);


	cout << dist[e] << '\n';
	vector<int> route;

	route.push_back(e);
	int now = e;
	while (now != s) {
		now = prevNode[now];
		route.push_back(now);
	}


	cout << route.size() << '\n';
	for (int i = route.size() - 1; i>=0; i--) {

		cout << route[i] << ' ';
	}
	

	return 0;
}