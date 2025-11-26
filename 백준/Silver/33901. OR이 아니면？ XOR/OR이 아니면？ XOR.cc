#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;


int n, m, k;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> k;

    vector<int> A;
    vector<ll> cache;
    A.resize(n);
    cache.resize(140000, 0);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    ll ans = 0;
    
    int r = 0;
    for (int i = 0; i < n; i++) {
        
        while (r < n && r - i <= m) {
            cache[A[r]]++;
            r++;
        }

        cache[A[i]]--;

        int target = A[i] ^ k;
        ans += cache[target];

    }
    cout << ans << '\n';

    

    return 0;
}