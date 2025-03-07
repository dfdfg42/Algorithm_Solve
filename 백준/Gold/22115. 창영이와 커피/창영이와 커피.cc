#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> coffees(n);
    for (int i = 0; i < n; i++) {
        cin >> coffees[i];
    }


    vector<int> dp(k + 1, INF);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        int caffeine = coffees[i];

        for (int j = k; j >= caffeine; j--) {
            dp[j] = min(dp[j], dp[j - caffeine] + 1);
        }
    }

    if (dp[k] == INF)
        cout << -1 << "\n";
    else
        cout << dp[k] << "\n";

    return 0;
}
