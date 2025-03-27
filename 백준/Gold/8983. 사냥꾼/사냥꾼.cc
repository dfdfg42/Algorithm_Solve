#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

vector<pair<ll, ll>> animals;
vector<ll> shooters;

int n, m;
ll l;

bool isReach(ll shooter , ll ax , ll ay) {
    ll a = abs(ax - shooter) + ay;

    if (a <= l) {
        return true;
    }
    else {
        return false;
    }
}

bool bs(ll ax, ll ay) {

    ll l = 1;
    ll r = m;

    while (l <= r) {
        ll mid = (l + r) / 2;

        if (isReach(shooters[mid], ax, ay))
            return true;

        if (shooters[mid] >= ax) {
            r = mid -1;
        }
        else if (shooters[mid] < ax) {
            l = mid + 1;
        }

    }

    return false;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> n >> l;

    animals.resize(n+1);
    shooters.resize(m+1);


    for (int i = 1; i <= m; i++) {
        cin >> shooters[i];
        
    }
    sort(shooters.begin(), shooters.end());

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        cin >> animals[i].first >> animals[i].second;

        if (bs(animals[i].first, animals[i].second)) ans++;
    }

    cout << ans << '\n';

    return 0;
}
