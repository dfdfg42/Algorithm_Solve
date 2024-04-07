#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int V, N;
    cin >> V >> N;
    vector<int> coins(V);
    vector<long long> dp(N+1, 0);
    dp[0] = 1;
    for (int i = 0; i < V; i++) {
        cin >> coins[i];
    }

    for (auto coin : coins) {
        for (int i = coin; i <= N; i++) {
            dp[i] += dp[i - coin];
        }
    }

    cout << dp[N] << '\n';

    return 0;
}
