#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <deque>
#include <algorithm>
#include <list>

using namespace std;

typedef long long ll;

struct Node {

	int u, v;
	int cost;

	bool operator<(const Node&  other) const {

		return cost > other.cost;
	}

};

const int INF = 987654321;
int N, M;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	vector<Node> graph;

	vector<vector<int>> dist(N + 1, vector<int>(N + 1, INF));

	for (int i = 0; i <= N; i++) {
		dist[i][i] = 0;
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		dist[a][b] = 1;
		dist[b][a] = 1;
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
	int minKebin = INF;

	for (int i = 1; i <= N; i++) {

		int temp = 0;
		for (int j = 1; j <= N; j++) {
			if (i == j) continue;

			temp += dist[i][j];
		}

		if (temp < minKebin) {
			minKebin = temp;
			ans = i;
		}
	}

	//for (int i = 1; i <= N; i++) {
	//	for (int j = 1; j <= N; j++) {
	//		if (dist[i][j] == INF) cout << "F ";
	//		else
	//		cout << dist[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}

	cout << ans << '\n';

	return 0;
}