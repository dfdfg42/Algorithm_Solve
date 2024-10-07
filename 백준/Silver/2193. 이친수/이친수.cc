#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    long long n;
    cin >> n;
    
    vector<vector<long long>> dp(n+1,vector<long long>(2));
    // 이친수는 1이 두번 나타나지 않음
    // dp[i][j] = i길이의 j로 끝나는 이친수 의 개수 = dp[i][0] = dp[i-1][0] + dp[i-1][1] 
    // dp[i][1] = dp[i-1][0] 

    dp[1][0] = 0;
    dp[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = dp[i - 1][0];
    }

    cout << dp[n][0] + dp[n][1] << '\n';

    return 0;
}
