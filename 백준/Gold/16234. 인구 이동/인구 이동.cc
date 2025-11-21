#include <iostream>
#include <cmath>
#include <tuple>
#include <vector>
#include <map>
#include <queue> 
#include <algorithm>

using namespace std;

typedef long long ll;


vector<vector<int>> board;
int N, L, R;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> L >> R;

	board.resize(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	bool isMoved = false;
	int moveCount = 0;

	while (true) {

		isMoved = false;
		vector<vector<bool>> visited(N, vector<bool>(N, false));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j]) {

					int sumPeople = 0;
					int visitCount = 0;

					queue<pair<int, int>> q;
					q.push({ i,j });
					visitCount++;
					sumPeople += board[i][j];
					visited[i][j] = true;

					vector<pair<int, int>> visitNodes;
					visitNodes.push_back({ i,j });

					while (!q.empty()) {
						int y = q.front().first;
						int x = q.front().second;
						q.pop();

						for (int t = 0; t < 4; t++) {
							int ny = y + dy[t];
							int nx = x + dx[t];

							if (0 > ny || ny >= N || 0 > nx || nx >= N) continue;
							if (visited[ny][nx]) continue;
							if (abs(board[ny][nx] - board[y][x]) <L ||abs( board[ny][nx] - board[y][x]) > R) continue;
							if (abs(board[ny][nx] - board[y][x]) == 0)continue;

							q.push({ ny,nx });
							visited[ny][nx] = true;
							visitNodes.push_back({ ny,nx });
							visitCount++;
							sumPeople += board[ny][nx];
							isMoved = true;
						}

					}

					for (auto a : visitNodes) {
						board[a.first][a.second] = sumPeople / visitCount;
					}


				}
			}
		}

		//cout << " check : " << moveCount << '\n';
		if (isMoved) moveCount++;
		if (!isMoved) break;
	}

	//for (int i = 0; i < N; i++) {
	//	for (int j = 0; j < N; j++) {
	//		cout << board[i][j]<< ' ';
	//	}
	//	cout << '\n';
	//}

	cout << moveCount << '\n';

	return 0;
}