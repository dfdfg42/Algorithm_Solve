#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <queue>
#include <unordered_map>
#include <tuple>
#include <algorithm>
#include <map>
#include <deque>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;
typedef long long ll;



void solve() {

    ll n, m;
    cin >> n >> m;

    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {

        dp[i] = dp[i - 1] % 1000000007;
        if (i >= m) {
            dp[i] += dp[i - m] %1000000007;
        }
        
        

    }

    cout << dp[n] % 1000000007 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}