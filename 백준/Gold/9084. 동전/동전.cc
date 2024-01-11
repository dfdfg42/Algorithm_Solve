#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        vector<int> coins(N + 1);
        for (int i = 1; i <= N; i++) {
            cin >> coins[i];
        }

        int M;
        cin >> M;

        vector<vector<ll>> dp(N + 1, vector<ll>(M + 1, 0));
        for (int i = 0; i <= N; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= coins[i]) {
                    dp[i][j] += dp[i][j - coins[i]];
                }
            }
        }

        cout << dp[N][M] << '\n';
    }

    return 0;
}
