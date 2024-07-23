#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
    ll n;
    cin >> n;
    vector<ll> values(n);
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }
    sort(values.begin(), values.end());

    ll ans = 0;
    for (int i = 0; i < n - 2; i++) {
        ans = max(ans, abs(values[n - 1] + values[i] - values[i + 1] * 2));
    }
    for (int i = 1; i < n - 1; i++){

        ans = max(ans, abs(-values[0] + values[i] * 2 - values[i + 1]));
    }
    cout << ans << '\n';
}
