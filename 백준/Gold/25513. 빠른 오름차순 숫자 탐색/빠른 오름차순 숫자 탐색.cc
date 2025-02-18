#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 보드 입력
    vector<vector<int>> board(5, vector<int>(5));
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> board[i][j];
        }
    }

    int r, c;
    cin >> r >> c;

    // 3차원 방문 배열: visited[y][x][stage] 
    // stage: 현재까지 방문한 순서 (0이면 아직 1부터 방문 안함, 6이면 모두 방문)
    vector<vector<vector<bool>>> visited(5, vector<vector<bool>>(5, vector<bool>(7, false)));

    // BFS 큐: (y, x, stage, steps)
    queue<tuple<int, int, int, int>> q;
    q.push({ r, c, 0, 0 });
    visited[r][c][0] = true;

    int dy[4] = { 0, 0, 1, -1 };
    int dx[4] = { 1, -1, 0, 0 };

    int ans = -1;

    while (!q.empty()) {
        auto [y, x, stage, steps] = q.front();
        q.pop();

        // 6까지 모두 방문한 경우 정답 처리
        if (stage == 6) {
            ans = steps;
            break;
        }

        // 4방향 이동
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            // 보드 범위 체크 및 -1(이동 불가) 칸 제외
            if (ny < 0 || ny >= 5 || nx < 0 || nx >= 5) continue;
            if (board[ny][nx] == -1) continue;

            int nextStage = stage;
            // 다음 방문해야 할 숫자(stage+1)가 있으면 진행 상태 업데이트
            if (stage < 6 && board[ny][nx] == stage + 1) {
                nextStage = stage + 1;
            }

            if (!visited[ny][nx][nextStage]) {
                visited[ny][nx][nextStage] = true;
                q.push({ ny, nx, nextStage, steps + 1 });
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
