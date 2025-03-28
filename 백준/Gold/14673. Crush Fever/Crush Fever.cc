#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int m, n;
int bestScore;
vector<vector<int>> board;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, 1,-1 };

void gravity(vector<vector<int>>& tBoard) {
    // 아래로 떨어뜨리는 처리
    for (int col = 0; col < m; col++) {
        int emptyRow = n - 1;
        for (int row = n - 1; row >= 0; row--) {
            if (tBoard[row][col] != 0) {
                tBoard[emptyRow][col] = tBoard[row][col];
                if (emptyRow != row) {
                    tBoard[row][col] = 0;
                }
                emptyRow--;
            }
        }
    }
}

void dfs(int depth, int Score, vector<vector<int>>& tBoard) {

    gravity(tBoard);

    if (depth == 3) {
        bestScore = max(bestScore, Score);
        return;
    }


    vector<vector<bool>> visited(n, vector<bool>(m, false));
    bool foundMove = false;  

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            
            if (tBoard[i][j] != 0 && !visited[i][j]) {

                foundMove = true;
                int chosen = tBoard[i][j];

                
                queue<pair<int, int>> q;
                vector<pair<int, int>> connected; 
                q.push({ i, j });
                visited[i][j] = true;
                connected.push_back({ i, j });

                while (!q.empty()) {
                    auto [cy, cx] = q.front();
                    q.pop();
                    for (int d = 0; d < 4; d++) {
                        int ny = cy + dy[d];
                        int nx = cx + dx[d];
                        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
                        if (!visited[ny][nx] && tBoard[ny][nx] == chosen) {
                            visited[ny][nx] = true;
                            q.push({ ny, nx });
                            connected.push_back({ ny, nx });
                        }
                    }
                }


                vector<vector<int>> tempBoard = tBoard;
                for (auto& cell : connected) {
                    tempBoard[cell.first][cell.second] = 0;
                }

                int count = (int)connected.size();

                int gained = count * count;

                dfs(depth + 1, Score + gained, tempBoard);
            }
        }
    }

    // 만약 어떤 칸도 제거할 수 없었다면, 그 상태에서 depth가 3 이하더라도
    // 더 이상 진행할 수 없으므로(이동 불가) 최고 점수 갱신만 하고 끝
    if (!foundMove) {
        bestScore = max(bestScore, Score);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> n;
    board.resize(n, vector<int>(m, 0));

    bestScore = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    // 초기 단계에서 depth=0, Score=0
    dfs(0, 0, board);

    cout << bestScore << '\n';

    return 0;
}
