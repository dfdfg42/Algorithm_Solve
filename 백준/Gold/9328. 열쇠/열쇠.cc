#include<iostream>
#include<vector>
#include<algorithm>
#include <climits>
#include <queue>
#include <string>

using namespace std;



int T, H, W;

vector<vector<char>> board;
vector<vector<int>> dist;
vector<vector<pair<int, int>>> wait;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

struct Node {
	int y, x;
};

bool check(int y, int x) {
	if (y < 0 || y >= H || x < 0 || x >= W) return false;

	return true;
}

void solve() {

	cin >> H >> W;
	board.clear();
	board.resize(H, vector<char>(W));
	dist.clear();
	dist.resize(H, vector<int>(W,INT_MAX));
	wait.clear();
	wait.resize(26);

	int totalDocs = 0;

	vector<pair<int, int>> docs;

	for (int i = 0; i < H; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < W; j++) {
			board[i][j] = s[j];
		}
	}

	string key;
	cin >> key;

	int haveKey = 0;
	for (int i = 0; i < key.length(); i++) {
		haveKey |= 1 << (key[i] - 'a');
	}

	queue<Node> q;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {

				if (board[i][j] >= 'a' && board[i][j] <= 'z') {
					haveKey |= 1 << (board[i][j] - 'a');
					q.push({ i,j });
					dist[i][j] = 0;
				}
			}
		}
	}


	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (i == 0 || i == H - 1 || j == 0 || j == W - 1) {
				if (board[i][j] == '.') {
					q.push({ i,j });
					dist[i][j] = 0;
				}
				else if (board[i][j] == '$') {
					q.push({ i,j });
					totalDocs++;
					dist[i][j] = 0;
				}
				if (board[i][j] >= 'A' && board[i][j] <= 'Z') {

					int doorIdx = 1 << (board[i][j] - 'A');


					if ((haveKey & doorIdx) != 0) {
						q.push({ i,j });
					}
					else {
						wait[board[i][j] - 'A'].push_back({ i,j });
					}
					

				}

			}
		}
	}

	while (!q.empty()) {

		auto now = q.front();
		q.pop();

		int y = now.y;
		int x = now.x;


		for (int d = 0; d < 4; d++) {
			int ny = y + dy[d];
			int nx = x + dx[d];

			if (!check(ny, nx)) continue;

			if (board[ny][nx] == '*') continue;

			if (board[ny][nx] == '.') {
				if (dist[ny][nx] > dist[y][x] + 1) {
					dist[ny][nx] = dist[y][x] + 1;
					q.push({ ny,nx });
				}
			}

			if (board[ny][nx] == '$') {
				if (dist[ny][nx] > dist[y][x] + 1) {
					dist[ny][nx] = dist[y][x] + 1;
					board[ny][nx] = '.';
					totalDocs++;
					q.push({ ny,nx });
				}
			}

			//열쇠 얻음
			if (board[ny][nx] >= 'a' && board[ny][nx] <= 'z') {

				haveKey |= 1 << (board[ny][nx] - 'a');

				int keyNum = board[ny][nx] - 'a';
				for (auto a : wait[keyNum]) {
					q.push({ a.first,a.second });
					
				}
				wait[keyNum].clear();

				if (dist[ny][nx] > dist[y][x] + 1) {
					dist[ny][nx] = dist[y][x] + 1;
					q.push({ ny,nx });
				}

			}

			//문을 만남
			if (board[ny][nx] >= 'A' && board[ny][nx] <= 'Z') {

				int doorIdx = 1 << (board[ny][nx] - 'A');
				if ((haveKey & doorIdx) == 0) {
					wait[board[ny][nx]-'A'].push_back({ y,x });
					continue;
				}

				if (dist[ny][nx] > dist[y][x] + 1) {
					dist[ny][nx] = dist[y][x] + 1;
					q.push({ ny,nx });
				}


			}

		}

	}

	cout << totalDocs << '\n';

}

int main()
{
	//결국에 열쇠 가지고 문서 있는곳에 도달 할 수 있으면 무조건 
	//열쇠는 얻는거

	cin >> T;

	while (T--) {
		solve();
	}

	return 0;
}