#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <map>
using namespace std;
const int MOD = 1'000'000'007;


int solution(int n, vector<int> money) {
    int answer = 0;
    
    vector<int> dp(n+1);
    
    dp[0]= 1;
    for(auto m : money){
        for(int j=m; j<=n; j++){
            dp[j] += dp[j-m];
        }
    }
    
    return dp[n];
}