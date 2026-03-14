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

int T, W, H;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

vector<vector<char>> board;
vector<vector<int>> dist;
vector<vector<int>> fireDist;

bool check(int y, int x) {
	if (y < 0 || y >= H || x < 0 || x >= W) {
		return false;
	}

	return true;
}

int solve() {

	cin >> W >> H;

	board.clear();
	dist.clear();
	board.resize(H, vector<char>(W));
	dist.resize(H, vector<int>(W, INT_MAX));
	fireDist.clear();
	fireDist.resize(H, vector<int>(W, INT_MAX));

	queue<pair<int, int>> fireQ,personQ;

	for (int i = 0; i < H; i++) {
		string s; cin >> s;
		for (int j = 0; j < W; j++) {
			board[i][j] = s[j];
			if (board[i][j] == '@') {
				//시작위치 받아두고
				personQ.push({ i,j });
				dist[i][j] = 0;
			}
			else if (board[i][j] == '*') {
				fireQ.push({ i,j });
				fireDist[i][j] = 0;
			}
		}
	}

	while (!fireQ.empty()) {

		int y = fireQ.front().first;
		int x = fireQ.front().second;

		fireQ.pop();

		for (int d = 0; d < 4; d++) {
			int ny = y + dy[d];
			int nx = x + dx[d];

			if (!check(ny, nx)) continue;
			if (board[ny][nx] == '#') continue;

			if (fireDist[ny][nx] != INT_MAX) continue;

			if (fireDist[ny][nx] > fireDist[y][x] + 1) {
				fireDist[ny][nx] = fireDist[y][x] + 1;
				fireQ.push({ ny,nx });
			}

		}

	}



	while (!personQ.empty()) {

		int y = personQ.front().first;
		int x = personQ.front().second;

		personQ.pop();

		for (int d = 0; d < 4; d++) {
			int ny = y + dy[d];
			int nx = x + dx[d];

			if (!check(ny, nx)) return dist[y][x] + 1;
			if (board[ny][nx] == '#') continue;

			if (dist[ny][nx] != INT_MAX) continue;

			if (dist[ny][nx] >dist[y][x] + 1) {
				if (fireDist[ny][nx] <= dist[y][x] + 1) continue;
				dist[ny][nx] = dist[y][x] + 1;
				
				personQ.push({ ny,nx });
			}

		}

	}


	

	return INT_MAX ;

}

int main()
{

	cin >> T;

	while (T--) {

		int ans = solve();
		if (ans == INT_MAX) {
			cout << "IMPOSSIBLE\n";
		}
		else {
			cout << ans << '\n';
		}

	}
	

	return 0;
}