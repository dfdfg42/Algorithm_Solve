#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <cstring>

const int INF = INT_MAX;

using namespace std;
int main()
{
	int t, c, ts, te;
	cin >> t >> c >> ts >> te;

	vector<vector<pair<int, int>>> nodes(t+1);// 비용,연결된노드

	for (int i = 0; i < c; i++) {
		int r1, r2, ci;
		cin >> r1 >> r2 >> ci;
		//양방향 노드
		nodes[r1].push_back({ ci,r2 });
		nodes[r2].push_back({ ci,r1 });
	}

	int dist[2501];
	fill(dist, dist + 2501, INF);
	dist[ts] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

	q.push({0, ts});

	while (!q.empty()) {

		int cost = q.top().first;
		int now = q.top().second;

		q.pop();

		if (cost > dist[now]) continue;
		for (auto next : nodes[now]) {
			int nextNode = next.second;
			int w = next.first;

			if (cost + w < dist[nextNode]) {
				dist[nextNode] = dist[now] + w;
				q.push({ cost + w, nextNode });
			}
			
		}


	}

	cout << dist[te] << '\n';


	return 0;
}

