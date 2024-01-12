#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int n;
        double m;
        cin >> n >> m;
        if (n == 0 && m == 0.00) break;

        int M = static_cast<int>(m * 100 + 0.5);
        vector<vector<int>> dp(n + 1, vector<int>(M + 1, 0));
        vector<int> c(n + 1), p(n + 1);

        for (int i = 1; i <= n; ++i) {
            double price;
            cin >> c[i] >> price;
            p[i] = static_cast<int>(price * 100 + 0.5);
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= M; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (j >= p[i]) {
                    dp[i][j] = max(dp[i-1][j], dp[i][j - p[i]] + c[i]);
                }
            }
        }
        cout << dp[n][M] << '\n';
    }
    return 0;
}
