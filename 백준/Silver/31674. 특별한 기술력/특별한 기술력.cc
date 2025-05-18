#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int64 MOD = 1'000'000'007LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<int64> H(N);
    for (auto &h : H) cin >> h;
    sort(H.begin(), H.end());         

    int64 pow2 = 1;                   
    int64 ans  = 0;
    for (int i = 0; i < N; ++i) {
        ans = (ans + H[i] % MOD * pow2) % MOD;
        pow2 = (pow2 << 1) % MOD;      
    }

    cout << ans << '\n';
    return 0;
}
