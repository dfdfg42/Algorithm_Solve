#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <deque>
#include <algorithm>
#include <list>
#include <queue>

using namespace std;

typedef long long ll;

const int INF = 987654321;
int n, m;
vector<vector<int>> board;
vector<vector<int>> dist;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	board.resize(n, vector<int>(m));
	dist.resize(n, vector<int>(m,INF));

	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2) {
				q.push({ i,j });
				dist[i][j] = 0;
			}
		}
	}



	while (!q.empty()) {

		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int d = 0; d < 4; d++) {
			int ny = y + dy[d];
			int nx = x + dx[d];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

			if (board[ny][nx] == 0 || dist[ny][nx] != INF) continue;

			dist[ny][nx] = dist[y][x] + 1;
			q.push({ ny,nx });
		}

	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dist[i][j] == INF && board[i][j] == 1) {
				cout << "-1 ";
			}
			else if (dist[i][j] == INF) {
				cout << "0 ";
			}
			else
			cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}