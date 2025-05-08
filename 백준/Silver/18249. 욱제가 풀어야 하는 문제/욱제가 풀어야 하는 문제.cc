#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <algorithm>
#include <string>
#include <iomanip> 
#include <queue>
using namespace std;

const int mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    vector<int> dp(192'230, 0);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= 192'230; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
    }
    while (t--) {
        int n;
        cin >> n;
 

        cout << dp[n] << '\n';

    }

}
