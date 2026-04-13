#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <regex>

using namespace std;

typedef long long ll;

int N;
const int INF = 987654321;

bool check(int y, int x) {
    if (y < 0 || y >= N || x < 0 || x >= N) {
        return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    vector<vector<int>> board(N, vector<int>(N));
    vector<vector<int>> dp(N, vector<int>(N,INF));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    dp[0][0] = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            //오른쪽 아래쪽으로 숫자만큼 이동해서 더 최소로 이동 할 수 있는지

            if (i == N - 1 && j == N - 1) continue;

            int ny = i + board[i][j];
            int nx = j;

            if (check(ny, nx)) {
                dp[ny][nx] = min(dp[ny][nx], dp[i][j] + 1);
            }

            ny = i;
            nx = j + board[i][j];
            if (check(ny, nx)) {
                dp[ny][nx] = min(dp[ny][nx], dp[i][j] + 1);
            }

        }
    }

    cout << (dp[N - 1][N - 1] != INF ? "HaruHaru" : "Hing") << '\n';

    return 0;
}