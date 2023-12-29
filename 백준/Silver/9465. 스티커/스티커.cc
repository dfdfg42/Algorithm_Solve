#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> sticker(2, vector<int>(n + 1));
        vector<vector<int>> dp(2, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; i++) {
            cin >> sticker[0][i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> sticker[1][i];
        }

        dp[0][1] = sticker[0][1];
        dp[1][1] = sticker[1][1];

        for (int i = 2; i <= n; i++) {
            dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + sticker[0][i];
            dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + sticker[1][i];
        }

        cout << max(dp[0][n], dp[1][n]) << endl;
    }
    return 0;
}
