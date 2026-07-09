#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    vector<int> dp(n+1,0);
    
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
        dp[i] %= 1234567;
    }
    
    answer = dp[n-1];
    
    return answer;
}