#include<iostream>
#include<vector>
#include<algorithm>
#include <climits>
#include <queue>
#include <string>

using namespace std;

const int INF = 987654321;
int V, E;

vector<vector<int>> dist;
int main()
{
	cin >> V >> E;

	dist.resize(V + 1, vector<int>(V + 1,INF));

	for (int i = 0; i < E; i++) {
		int u, v, c;
		cin >> u >> v >> c;

		dist[u][v] = c;
	}

	for (int i = 1; i <= V; i++) {
		dist[i][i] = 0;
	}
	
	for (int k = 1; k <= V; k++) {
		for (int i = 1; i <= V; i++) {
			for (int j = 1; j <= V; j++) {

				if (dist[i][k] != INF && dist[k][j] != INF) {
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}

			}
		}
	}

	int ans = INT_MAX;
	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {

			if (i == j) continue;

			if (dist[i][j] == INF || dist[j][i] == INF) continue;

			ans = min(dist[i][j] + dist[j][i] ,ans);

		}
	}
	
	if (ans == INT_MAX) {
		cout << -1 << '\n';
	}else
	cout << ans << '\n';

	return 0;
}