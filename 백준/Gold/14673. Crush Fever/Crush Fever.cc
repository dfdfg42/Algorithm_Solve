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

// depth: 현재까지 제거한 횟수
// Score: 현재까지 획득한 점수
// tBoard: 현재 보드 상태
void dfs(int depth, int Score, vector<vector<int>>& tBoard) {
    // 중력 처리 (매 단계마다)
    gravity(tBoard);

    // 만약 3번 제거했다면 최고 점수 갱신 후 종료
    if (depth == 3) {
        bestScore = max(bestScore, Score);
        return;
    }

    // 이미 방문한 칸은 다시 BFS하지 않도록 visited 사용
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    bool foundMove = false;  // 이번 단계에서 제거할 수 있는 연결요소가 있는지

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // 0이 아니고 아직 방문 안 했다면
            if (tBoard[i][j] != 0 && !visited[i][j]) {

                foundMove = true;
                int chosen = tBoard[i][j];

                // BFS로 연결된 칸들 전부 찾기
                queue<pair<int, int>> q;
                vector<pair<int, int>> connected; // 연결된 좌표 저장
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

                // 이제 이 연결요소를 제거(0으로 만들)하는 경우를 시뮬레이션
                // 임시 보드 복사
                vector<vector<int>> tempBoard = tBoard;
                for (auto& cell : connected) {
                    tempBoard[cell.first][cell.second] = 0;
                }

                int count = (int)connected.size();
                // 점수 = count^2
                int gained = count * count;

                // 재귀 호출
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
