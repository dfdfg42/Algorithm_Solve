#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, K;
    cin >> T >> K;

    vector<pair<int, int>> coins(K);
    for (int i = 0; i < K; ++i) {
        cin >> coins[i].first >> coins[i].second;
    }

    vector<int> dp(T + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < K; ++i) {
        int value = coins[i].first;
        int count = coins[i].second;


        for (int j = T; j >= 0; --j) {
            if (dp[j] == 0) continue; 

            for (int k = 1; k <= count; ++k) {
                if (j + value * k > T) break;
                dp[j + value * k] += dp[j];
            }
        }
    }

    cout << dp[T] << '\n';
    return 0;
}
