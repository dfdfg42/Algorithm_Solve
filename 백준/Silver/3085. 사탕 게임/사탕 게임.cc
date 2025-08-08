#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int n;
vector<vector<char>>board;
int ans;

bool canflip(int y, int x, int ny, int nx) {
    if (0 <= ny && ny < n && 0 <= nx && nx < n) {
        if (board[ny][nx] != board[y][x]) {
            return true;
        }
    }
    return false;
}

void check(vector<vector<char>>& cboard) {
    for (int i = 0; i < n; i++) {
        int run = 1;
        for (int j = 1; j < n; j++) {
            if (cboard[i][j] == cboard[i][j - 1]) run++;
            else {
                ans = max(ans, run);
                run = 1;
            }
        }
        ans = max(ans, run);
    }
    for (int j = 0; j < n; j++) {
        int run = 1;
        for (int i = 1; i < n; i++) {
            if (cboard[i][j] == cboard[i - 1][j]) run++;
            else {
                ans = max(ans, run);
                run = 1;
            }
        }
        ans = max(ans, run);
    }
}

void letsflip(int y, int x, int ny, int nx) {
    vector<vector<char>> tempBoard = board;
    char temp = tempBoard[ny][nx];
    tempBoard[ny][nx] = tempBoard[y][x];
    tempBoard[y][x] = temp;
    check(tempBoard);
}

void solve() {

    cin >> n;
    board.resize(n, vector<char>(n));
    ans = 0;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < (int)s.length(); j++) {
            board[i][j] = s[j];
        }
    }

    check(board);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int t = 0; t < 4; t++) {
                int ny = i + dy[t];
                int nx = j + dx[t];
                if (canflip(i, j, ny, nx)) {
                    letsflip(i, j, ny, nx);
                }
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
