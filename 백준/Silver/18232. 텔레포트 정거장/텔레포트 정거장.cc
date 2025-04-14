#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <climits>
#include <tuple>
using namespace std;

typedef long long ll;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
	int n, m;
	cin >> n >> m;

    int s, e;
    cin >> s >> e;

	vector<bool> visited(n + 1, false);
	vector<int> dist(n + 1, INT_MAX);

	vector<vector<int>> graph(n + 1);

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	queue<pair<int, int>> q; //위치,거리

	q.push({ s, 0 });

	visited[s] = true;
	dist[s] = 0;
	while (!q.empty()) {
		int cur = q.front().first;
		int cur_dist = q.front().second;
		if (cur == e) {
			cout << cur_dist;
			return 0;
		
		}
		q.pop();
		for (int next : graph[cur]) {
			if (!visited[next]) {
				visited[next] = true;
				dist[next] = cur_dist + 1;
				q.push({ next, dist[next] });

			}

		}

		if (cur - 1 > 0 && !visited[cur - 1]) {
			visited[cur - 1] = true;
			dist[cur - 1] = cur_dist + 1;
			q.push({ cur - 1, dist[cur - 1] });
		}

		if (cur + 1 <= n && !visited[cur + 1]) {
			visited[cur + 1] = true;
			dist[cur + 1] = cur_dist + 1;
			q.push({ cur + 1, dist[cur + 1] });
		}

	}
    return 0;
}
