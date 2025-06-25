#include <iostream>

using namespace std;

long long dp[15][101][101]; 
const int dr[] = { 0, 0, -1, 1, 1, -1 };
const int dc[] = { 1, -1, 1, -1, 0, 0 };

const int CENTER = 50; 
void solve() {
   
    dp[0][CENTER][CENTER] = 1;

  
    for (int k = 1; k <= 14; ++k) {
        for (int r = 0; r < 101; ++r) {
            for (int c = 0; c < 101; ++c) {

                if (dp[k - 1][r][c] > 0) {

                    for (int i = 0; i < 6; ++i) {
                        int nr = r + dr[i];
                        int nc = c + dc[i];
                       dp[k][nr][nc] += dp[k - 1][r][c];
                    }
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        cout << dp[n][CENTER][CENTER] << "\n";
    }

    return 0;
}