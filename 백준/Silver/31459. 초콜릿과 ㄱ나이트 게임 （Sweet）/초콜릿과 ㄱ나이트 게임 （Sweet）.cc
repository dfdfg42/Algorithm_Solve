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

int T;
int X, Y, x, y;

bool check(int y, int x) {
	if (y < 1 || y >= Y + 1 || x < 1 || x >= X + 1) {
		return false;
	}

	return true;
}

void solve() {

	cin >> X >> Y >> x >> y;

	vector<vector<bool>> board(Y + 1, vector<bool>(X + 1));

	int cnt = 0;
	for (int i = 1; i <= Y; i++) {
		for (int j = 1; j <= X; j++) {
			if (board[i][j] == false) {
				board[i][j] = true;
				if (check(i + y, j + x)) {
					board[i + y][j + x] = true;
				}

				cnt++;
			}

		}
	}

	cout << cnt << '\n';

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;

	while (T--) {
		solve();
	}
	
	
	return 0;
}