#include <bits/stdc++.h>
using namespace std;
static const int MOD = 1'000'000'007;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> cost(n);
    for(int i = 0; i < n; i++){
        long long a, m;
        cin >> a >> m;

        cost[i] = 6 * int(a / 250) * int(m / 15);
    }
    int C1, C2;
    cin >> C1 >> C2;

    vector<int> dp(C2 + 1);
    dp[0] = 1;
    for(int x : cost){
        if (x > C2) continue;  
        for(int j = C2; j >= x; --j){
            dp[j] = (dp[j] + dp[j - x]) % MOD;
        }
    }

    long long ans = 0;
    for(int j = C1; j <= C2; ++j){
        ans = (ans + dp[j]) % MOD;
    }
    cout << ans << "\n";
    return 0;
}
