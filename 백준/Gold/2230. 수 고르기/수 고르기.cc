#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    vector<int> vec(n);

    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());

    int l = 0;
    int r = 1;

    ll now = LLONG_MAX; 

    for (; r < n; r++) {

        while (vec[r] - vec[l] >= m && l < r) {

            now = min(now, (ll)(vec[r] - vec[l]));
            l++;

        }
    }

    cout << now << '\n';
    
    return 0;
}
