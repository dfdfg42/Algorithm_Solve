#include <vector>
using namespace std;

const int MOD = 20170805;

int solution(int m, int n, vector<vector<int>> city_map) {
    // dp[0][y][x] = 위에서 아래로 와서 (y, x)에 도착한 경우
    // dp[1][y][x] = 왼쪽에서 오른쪽으로 와서 (y, x)에 도착한 경우
    vector<vector<vector<int>>> dp(2, vector<vector<int>>(m, vector<int>(n, 0)));

    // 첫 열 초기화: 위에서 아래로만 올 수 있음
    for (int y = 1; y < m; y++) {
        if (city_map[y][0] == 1) break;
        dp[0][y][0] = 1;
    }

    // 첫 행 초기화: 왼쪽에서 오른쪽으로만 올 수 있음
    for (int x = 1; x < n; x++) {
        if (city_map[0][x] == 1) break;
        dp[1][0][x] = 1;
    }

    for (int y = 1; y < m; y++) {
        for (int x = 1; x < n; x++) {
            if (city_map[y][x] == 1) continue;

            // 위에서 오는 경우
            if (city_map[y - 1][x] != 1) {
                if (city_map[y - 1][x] == 2) {
                    dp[0][y][x] = dp[0][y - 1][x];
                } else {
                    dp[0][y][x] = (dp[0][y - 1][x] + dp[1][y - 1][x]) % MOD;
                }
            }

            // 왼쪽에서 오는 경우
            if (city_map[y][x - 1] != 1) {
                if (city_map[y][x - 1] == 2) {
                    dp[1][y][x] = dp[1][y][x - 1];
                } else {
                    dp[1][y][x] = (dp[0][y][x - 1] + dp[1][y][x - 1]) % MOD;
                }
            }
        }
    }

    // m == 1, n == 1인 경우
    if (m == 1 && n == 1) return 1;

    return (dp[0][m - 1][n - 1] + dp[1][m - 1][n - 1]) % MOD;
}