#include <iostream>
#include <vector>
#include <utility>
#include <climits>

using namespace std;

vector<vector<int>> board;
vector<vector<int>> tempBoard;
int n, m;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

void contagion() {
    vector<vector<int>> nextBoard = tempBoard;

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < m; j++) {

            if (tempBoard[i][j] == 3) {

                for (int t = 0; t < 4; t++) {
                    int nx = j + dx[t];
                    int ny = i + dy[t];

                    if (0 <= ny && ny < n && 0 <= nx && nx < m) {
                        if (nextBoard[ny][nx] != 3) {
                            nextBoard[ny][nx] = 3;
                        }
                    }

                }

            }

        }
    }
    tempBoard = nextBoard;
}

bool isAllContagion() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 1 && tempBoard[i][j] != 3) {
                return false;
            }
        }
    }

    return true;
}

int main() {

    cin >> n >> m;

    board.resize(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < s.length(); j++) {
            board[i][j] = s[j] - '0';
        }
    }

    vector<pair<int, int>> emptyCells;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 0) {
                emptyCells.push_back({ i, j });
            }
        }
    }

    int minSec = INT_MAX;

    for (size_t i = 0; i < emptyCells.size(); ++i) {
        for (size_t j = i + 1; j < emptyCells.size(); ++j) {
            pair<int, int> a = emptyCells[i];
            pair<int, int> b = emptyCells[j];

            // 복사후 감염원 설정
            tempBoard = board;
            tempBoard[a.first][a.second] = 3;
            tempBoard[b.first][b.second] = 3;

            int sec = 0;
            while (!isAllContagion()) {
                contagion();
                sec++;
            }
            minSec = min(sec, minSec);
        }
    }

    cout << minSec << '\n';

    return 0;
}
