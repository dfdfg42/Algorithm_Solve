#include <iostream>
using namespace std;

typedef long long ll;
const int MOD = 1000000007;

// 빠른 거듭제곱 함수: base^exp % mod를 계산
ll modExp(ll base, ll exp, int mod) {
    ll result = 1;
    while(exp > 0) {
        if(exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    ll ans = 0;
    
    for (int i = 0; i < n; i++) {
        int a;
        ll b;
        cin >> a >> b;
        
        // 상수항은 미분 결과가 0이므로 무시
        if(b == 0) continue;
        
        // 미분 후 항의 값: a * b * 2^(b-1)
        ll power = modExp(2, b - 1, MOD);
        ll term = ((ll)a * b) % MOD;
        term = (term * power) % MOD;
        
        ans = (ans + term) % MOD;
    }
    
    cout << ans << "\n";
    return 0;
}
