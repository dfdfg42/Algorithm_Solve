#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;

    vector<int> wines(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> wines[i];
    }

    vector<int> dp(n + 1, 0);
    dp[1] = wines[1];
    if (n > 1) {
        dp[2] = wines[1] + wines[2];
    }

    for (int i = 3; i <= n; i++) {
        dp[i] = max({ dp[i - 1], wines[i] + wines[i - 1] + dp[i - 3], wines[i] + dp[i - 2] });
    }

    cout << dp[n] << '\n';

    return 0;
}
