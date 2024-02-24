#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> board;
vector<vector<long long>> dp; // DP를 위한 2차원 벡터
int dx[2] = {1, 0};
int dy[2] = {0, 1};
int N;

long long dfs(int row, int col) {
    // 목적지에 도달한 경우
    if (row == N-1 && col == N-1) return 1;

    // 이미 계산된 경우
    if (dp[row][col] != -1) return dp[row][col];

    dp[row][col] = 0; // 현재 위치에서의 경로 수 초기화
    for (int i = 0; i < 2; i++) {
        int nx = row + dx[i] * board[row][col];
        int ny = col + dy[i] * board[row][col];

        if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
            dp[row][col] += dfs(nx, ny); // 경로 수 누적
        }
    }
    return dp[row][col];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    board.assign(N, vector<int>(N));
    dp.assign(N, vector<long long>(N, -1)); // DP 테이블 초기화

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    cout << dfs(0, 0) << '\n';

    return 0;
}
