#include<iostream>
#include<vector>
#include<algorithm>
#include <climits>
#include <queue>
#include <string>
#include <map>
using namespace std;
typedef long double ld;

const int INF = 987654321;
int N, M;
vector<vector<int>> dist;

int main()
{
	cin >> N >> M;

	dist.resize(N + 1, vector<int>(N + 1, INF));

	for (int i = 0; i < M; i++) {

		int u, v;
		cin >> u >> v;

		dist[u][v] = 1;

	}

	for (int i = 1; i <= N; i++) {
		dist[i][i] = 0;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {

				if (dist[i][k] != INF && dist[k][j] != INF) {

					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

				}

			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {

		bool can = true;

		for (int j = 1; j <= N; j++) {
			if (i == j) continue;
			if (dist[i][j] == INF && dist[j][i] == INF) {
				can = false;
				break;
			}
		}

		if (can) ans++;

	}



	cout << ans << '\n';
	

	return 0;
}