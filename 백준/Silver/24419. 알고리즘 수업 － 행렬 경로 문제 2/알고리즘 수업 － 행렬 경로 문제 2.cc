#include <iostream>
#include <vector>

using namespace std;

long long dp[1001][1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    if (!(cin >> n)) return 0;

    int temp;
    for (int i = 0; i < n * n; ++i) {
        cin >> temp;
    }

    int MOD = 1000000007;

    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 1;
        dp[0][i] = 1;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
        }
    }


    cout << dp[n][n] << " " << (long long)n * n << "\n";

    return 0;
}