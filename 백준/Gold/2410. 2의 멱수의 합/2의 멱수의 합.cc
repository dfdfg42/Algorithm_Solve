#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000000;

int main() {
    int n;

    cin >> n;

    vector<int> powers;

    for (int i = 0; (1 << i) <= n; i++) {
        powers.push_back(1 << i);
    }

    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int power : powers) {
        for (int i = power; i <= n; i++) {
            dp[i] = (dp[i] + dp[i - power]) % MOD;
        }
    }
         
    
    cout << dp[n] << endl;

    return 0;
}
