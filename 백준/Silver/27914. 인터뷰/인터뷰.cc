#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //연속된길이! = 가짓수

    int n, k, q;
    cin >> n >> k >> q;

    vector<ll> dp(4001,0);

    dp[1] = 1;
    for (int i = 2; i <= 4000; i++) {
        dp[i] = dp[i - 1] + i;
        //cout << dp[i] << '\n';
    }

    vector<int> v(n);
    vector<int> Q(q);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < q; i++) {
        cin >> Q[i];
    }

    for (auto a : Q) {

        int seq = 0;
        ll ans = 0;
        for (int i = 0; i < a; i++) {
            
            if (v[i] != k) {
                seq++;
                
            }
            else {
                ans += dp[seq];
                seq = 0;
            }
        }
        ans += dp[seq];

        cout << ans << '\n';
    }

    return 0;
}