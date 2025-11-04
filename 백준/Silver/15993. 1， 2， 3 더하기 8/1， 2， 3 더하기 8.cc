#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef long long ll;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    vector<vector<long long>> dp(100001, vector<long long>(2, 0));
    dp[1][1] = 1;
    dp[2][0] = dp[2][1] = 1;
    dp[3][0] = dp[3][1] = 2;

    for (int i = 4; i < 100001; i++) 
    {
        dp[i][0] = (dp[i - 1][1] + dp[i - 2][1] + dp[i - 3][1]) % 1000000009; 
        dp[i][1] = (dp[i - 1][0] + dp[i - 2][0] + dp[i - 3][0]) % 1000000009; 
    }

    while (T--)
    {
        int n;
        cin >> n;
        cout << dp[n][1] << " " << dp[n][0] << "\n";
    }

    return 0;
}