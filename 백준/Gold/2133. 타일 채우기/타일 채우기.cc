#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <regex>

using namespace std;

typedef long long ll;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<ll> dp(31, 0);
    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 3;
    dp[3] = 0;
    for (int i = 4; i <= N; i++) {

        if (i % 2 != 0) continue;

        dp[i] = dp[i - 2] * 3;

        for (int j = i - 4; j >= 0; j -= 2) {
            dp[i] += dp[j] * 2;
        }

    }

    cout << dp[N] << '\n';


    return 0;
}