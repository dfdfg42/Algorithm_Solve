#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>> board;


int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };


bool is_successful(int start_row) {

    vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(4, false)));

    int r = start_row;
    int c = 0;
    int d = 0;

    while (true) {

        if (visited[r][c][d]) {
            return true;
        }

        visited[r][c][d] = true;

        int move_dist = board[r][c];


        int next_r = r + dy[d] * move_dist;
        int next_c = c + dx[d] * move_dist;

        if (next_r < 0 || next_r >= n || next_c < 0 || next_c >= m) {
            return false;
        }

        r = next_r;
        c = next_c;
        d = (d + 1) % 4;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    board.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    vector<int> ans;

    for (int i = 0; i < n; i++) {
        if (is_successful(i)) {
            ans.push_back(i+1);
        }
    }

    if (ans.empty()) {
		cout << "0\n";
    }
    else {
		cout << ans.size() << "\n";
		for (auto a : ans) {
			cout << a << " ";
		}
    }

    return 0;
}