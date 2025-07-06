#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long ll;
int t;
int n, k;
ll ans;
ll diff;

void solve() {
    int n;
    ll K;
    cin >> n >> K;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int l = 0, r = n - 1;
    ll minDiff = LLONG_MAX;  
    ll count = 0;           

    while (l < r) {
        ll sum = v[l] + v[r];
        ll curDiff = llabs(sum - K);

        if (curDiff < minDiff) {
            minDiff = curDiff;
            count = 1;
        }
        else if (curDiff == minDiff) {
            count++;
        }


        if (sum > K) {
            r--;
        }
        else if (sum < K) {
            l++;
        }
        else { 
            l++;
            r--;
        }
    }

    cout << count << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while (t--) {
        solve();
    }



    return 0;
}