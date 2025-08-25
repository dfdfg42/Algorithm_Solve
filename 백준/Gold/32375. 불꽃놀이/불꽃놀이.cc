#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <set>
#include <cmath>
using namespace std;

typedef long long ll;
typedef long double ld;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; long long K;
    cin >>N >>  K;
    vector<long long> a(N);
    for (auto& x : a) cin >> x;

    sort(a.begin(), a.end());

    int i = 0, j = N - 1;
    int ans = 0;
    while (i < j) {
        if (a[j] >= K) {
            ans++;
            --j;
            
        }
        else if (a[i] + a[j] >= K) {
            ++ans;
            ++i; --j; 

        }
        else {
            ++i;                
        }
    }

    if (i == j && a[i] >=K) {
        ans++;
    }
    if (ans == 0) {
        cout << -1 << '\n';
    }else
    cout << ans << '\n';

    return 0;
}