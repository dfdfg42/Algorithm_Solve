#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef long double ld;

ll n, k;

vector<ll> kettle;

bool divideMak(ll size) {
    ll cnt = 0;

    for (auto a : kettle) {
        cnt += a / size;
    }

    if (cnt >= k) {
        return true;
    }

    return false;
}

void solve() {

    cin >> n >> k;
    kettle.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> kettle[i];
    }

    ll l = 0;
    ll r = 21474836481;

    ll ans = -1;

    while (l <= r) {
        ll mid = (l + r) / 2;

        if (divideMak(mid)) {
            ans = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }

    }
   
    cout << ans << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    solve();



    return 0;
}