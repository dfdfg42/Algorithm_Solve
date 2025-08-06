#include <vector>
using namespace std;

int solution(int n, vector<int> tops) {
    const int MOD = 10007;
    if (n == 0) return 1; // 문제 제한상 n>=1이지만 안전망

    auto mul = [&](long long x, long long y){ return (int)((x * y) % MOD); };
    auto sub = [&](int x, int y){ 
        int z = x - y; 
        if (z < 0) z += MOD; 
        return z; 
    };

    int dp0 = 1; // dp[0]
    int dp1 = (tops[0] == 1 ? 4 : 3) % MOD; // dp[1]

    for (int i = 2; i <= n; ++i) {
        int coef = (tops[i-1] == 1 ? 4 : 3);
        int dpi = sub(mul(coef, dp1), dp0); // dpi = coef*dp1 - dp0 (mod)
        dp0 = dp1;
        dp1 = dpi;
    }
    return dp1;
}
