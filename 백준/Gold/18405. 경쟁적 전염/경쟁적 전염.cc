#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <climits>
#include <tuple>
using namespace std;

typedef long long ll;

int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

	vector<vector<int>> board(n + 1, vector<int>(n + 1, 0));
    vector<vector<pair<int, int>>> virus(k+1);

    for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
			if (board[i][j] != 0) {
				virus[board[i][j]].push_back({ i, j });
			}
		}
    }

	int s, x, y;
	cin >> s >> x >> y;
    
	while (s--) {
		for (int i = 1; i <= k; i++) {
			if (virus[i].empty()) continue;
			vector<pair<int, int>> next_virus;
			for (auto a : virus[i]) {
				for (int d = 0; d < 4; d++) {
					int nr = a.first + dy[d];
					int nc = a.second+ dx[d];
					if (nr < 1 || nr > n || nc < 1 || nc > n) continue;
					if (board[nr][nc] != 0) continue;
					board[nr][nc] = i;
					next_virus.push_back({ nr, nc });
				}
			}
			virus[i] = next_virus;
		}
	}

	//for (int i = 1; i <= n; i++) {
	//	for (int j = 1; j <= n; j++) {
	//		cout << board[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}

	
	cout << board[x][y] << '\n';

    return 0;
}
