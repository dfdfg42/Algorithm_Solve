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


using namespace std;

typedef long long ll;



void solve() {

    vector<vector<ll>> dp (66,vector<ll> (10,0)); // [i][j] i자리수의 j로끝나는 오름수
    // [i][j] += [i-1][j]  / 0 ~ j
    for (int i = 0; i <= 9; i++) {
        dp[1][i] = 1;
    }

    for (int i = 1; i <= 65; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= j; k++) {
                dp[i][j] += dp[i - 1][k];
            }
        }
    }

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        ll ans = 0;
        for (int i = 0; i <= 9; i++) {
            ans += dp[n][i];
        }
        cout << ans  << '\n';
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();



    return 0;
}