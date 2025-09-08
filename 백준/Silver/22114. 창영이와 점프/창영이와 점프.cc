#include <iostream>
#include <vector>
#include <iomanip> 

using namespace std;

typedef long double ld;
typedef long long ll;

int n, k;
vector<vector<int>> dp;

vector<int> l;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    l.resize(n+1);
    int ans = 0;
    for (int i = 1; i < n; i++) {
        cin >> l[i];
    }

    dp.resize(2, vector<int>(n+1, 1));
    dp[0][0] = 1;
    dp[1][0] = 1;

    for (int i = 1; i < n; i++) {
        if (l[i] <= k) {
            dp[0][i] = dp[0][i - 1] + 1;
            dp[1][i] = dp[1][i - 1] + 1;
        }
        else {
            dp[0][i] = 1;
            dp[1][i] = max(dp[0][i - 1] + 1, 1);
        }

        ans = max(dp[1][i],ans);
        ans = max(dp[0][i], ans);

        //cout << dp[1][i] << ' ' << dp[0][i] <<'\n';
    }



    cout << ans << '\n';

    return 0;
}