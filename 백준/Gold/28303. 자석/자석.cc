#include <iostream>
#include <vector>
#include <algorithm> // max 함수를 사용하기 위해 필요합니다.

using namespace std;

typedef long long ll;

const ll INF = 4e18; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    ll k; 
    cin >> n >> k;

    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<ll> left(n, 0);

    left[0] = v[0] + 1 * k;
    for (int i = 1; i < n; i++) {
        left[i] = max(left[i - 1], v[i] + (ll)(i + 1) * k);
    }


    vector<ll> right(n, 0);

    right[n - 1] = v[n - 1] - (ll)n * k;
    for (int i = n - 2; i >= 0; i--) {
        right[i] = max(right[i + 1], v[i] - (ll)(i + 1) * k);
    }

    ll ans = -INF;


    for (int i = 1; i < n; i++) {

        ans = max(ans, left[i - 1] - (v[i] + (ll)(i + 1) * k));
    }


    for (int i = 0; i < n - 1; i++) {

        ans = max(ans, right[i + 1] - (v[i] - (ll)(i + 1) * k));
    }

    cout << ans << '\n';

    return 0;
}