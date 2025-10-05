#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string s;
    cin >> s;
    
    vector<vector<int>> dp(2, vector<int>(n+1, 0));

    //dp[0][i] = i번째까지 a 로만드는 방법 
    //dp[1][i] = i번째까지 b 로 만드는 방법

    
    for (int i = 1; i <= n; i++) {
        if (s[i-1] == 'B') {
            dp[0][i] = min(dp[0][i - 1] + 1, dp[1][i - 1] + 1);
            dp[1][i] = min(dp[0][i - 1] + 1, dp[1][i - 1] );
        }
        else if (s[i-1] == 'A') {
            dp[0][i] = min(dp[0][i - 1] , dp[1][i - 1] + 1);
            dp[1][i] = min(dp[0][i - 1] + 1, dp[1][i - 1] + 1);
        }
    }
    
    int ans = min(dp[0][n], dp[1][n] +1 );
    cout << ans << '\n';


    return 0;
}