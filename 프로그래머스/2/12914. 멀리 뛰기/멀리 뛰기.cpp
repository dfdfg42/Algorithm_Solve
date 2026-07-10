#include <string>
#include <vector>

using namespace std;

typedef long long ll;

long long solution(int n) {
    long long answer = 0;
    
    vector<ll> dp(n+1);
    
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    
    for(int i = 3; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
        dp[i] %= 1234567;
    }
    
    return dp[n];
}