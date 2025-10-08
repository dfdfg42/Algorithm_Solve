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


    int n, k, q;
    cin >> n >> k >> q;

    vector<ll> dp(n,0);


    vector<int> v(n);
    vector<int> Q(q);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int seq = 0;
    for (int i = 0; i < n; i++) {
  

        if (v[i] != k) {
            seq++;
        }
        else {
            seq = 0;
        }
        if (i == 0) dp[0] = dp[0] + seq;
        else
        dp[i] = dp[i - 1] + seq;
    }

    while(q--) {
        int input; cin >> input;
        cout << dp[input - 1] << '\n';
    }

    return 0;
}