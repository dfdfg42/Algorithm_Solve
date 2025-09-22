#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


typedef long long ll;
int n, m;

int dy[3] = { 1,1,1 };
int dx[3] = { -1,0,1 };

vector<vector<int>> board;
vector<vector<int>> dp;

const int mod = 1'000'000'007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    board.resize(n, vector<int>(m,0));
    dp.resize(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        if(board[n-1][i] == 1)
        dp[n - 1][i] = 1;
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < m; j++) {

            for (int t = 0; t < 3; t++) {
                int ny = i + dy[t];
                int nx = j + dx[t];
                if (n <= ny || 0 > nx || m <= nx) continue;
                if (board[ny][nx] == 0) continue;
                if (board[i][j] == 0) continue;

                dp[i][j] += dp[ny][nx];
                dp[i][j] %= mod;

            }

        }
    }

    //cout << '\n';
    //for (int i = 0; i < n; i++) {
    //    for (int j = 0; j < m; j++) {
    //        cout << dp[i][j] << ' ';
    //    }
    //    cout << '\n';
    //}

    int ans = 0;
    for (int i = 0; i < m; i++) {
        ans += dp[0][i] ;
        ans %= mod;
    }
    cout << ans << '\n';

    return 0;
}