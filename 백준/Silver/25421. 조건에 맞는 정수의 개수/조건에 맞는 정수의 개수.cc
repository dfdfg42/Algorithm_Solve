#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <cstring>

using namespace std;

typedef long long ll;

const int mod = 987'654'321;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    vector<vector<ll>> dp(n+1,vector<ll>(10,0)); //dp[i][j] = i 자리수의 j로 끝나는 조건을만족하는 수
    //dp[i][j] += dp[i-1][k] j와 k의차이 절대값 2 이하 

    for (int i = 1; i <= 9; i++) {
        dp[1][i] = 1;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= 9; j++) {
            for (int k = 1; k <= 9; k++) {
                if (abs(j - k) <= 2) {
                    dp[i][j] += dp[i-1][k];
                    dp[i][j] %= mod;
                }
            }
        }
    }

    ll ans = 0;
    for (int i = 1; i <= 9; i++) {
        ans += dp[n][i];
        ans %= mod;
    }

    cout << ans << '\n';

    return 0;
}