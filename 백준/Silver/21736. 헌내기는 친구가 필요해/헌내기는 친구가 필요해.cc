#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;


int N, M,ans;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

bool check(int y, int x) {

	if (y < 0 || y >= N || x < 0 || x >= M) return false;

	return true;

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ans = 0;
	cin >> N >> M;

	vector<vector<char>> board(N, vector<char>(M));
	vector<vector<bool>> visited(N, vector<bool>(M));

	queue<pair<int, int>> q;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			board[i][j] = s[j];
			if (board[i][j] == 'I') {
				q.push({ i,j });
				visited[i][j] = true;
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

			if (!check(ny, nx)) continue;

			if (board[ny][nx] == 'X' || visited[ny][nx] == true) continue;
			
			if (board[ny][nx] == 'P') {
				ans++;
			}

			visited[ny][nx] = true;
			q.push({ ny,nx });
		}

	}

	if (ans == 0) {
		cout << "TT\n";
	}
	else
	cout << ans << '\n';

	return 0;
}