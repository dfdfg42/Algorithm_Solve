#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, target;
vector<vector<int>> board;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> target;
	board.resize(n, vector<int>(n));

	int delta = 1;

	int y = n / 2;
	int x = n / 2;
	int dir = 0;
	int seq = 1;
	board[n / 2][n / 2] = 1;
	bool end = false;
	pair<int, int> found = { (n / 2)+1,(n / 2)+1 };

	bool flag = false;

	while (!flag) {

		for (int t = 0; t < 2; t++) {
			if (!flag) {
				for (int i = 0; i < delta; i++) {

					y += dy[dir];
					x += dx[dir];

					//cout << y << ' ' << x << '\n';
					board[y][x] = ++seq;
					if (seq == target) {
						found = { y + 1,x + 1 };
					}
					if (y == 0 && x == 0) {
						flag = true;
						break;
					}
				}
			}


			dir = (dir + 1) % 4;
		}
		delta++;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << found.first << ' ' << found.second << '\n';
}
