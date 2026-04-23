#include <string>
#include <vector>
#include <climits>
#include <iostream>

using namespace std;

const int mod = 1'000'000'007;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    dp[1][1] = 1;
    
    for(auto a : puddles){
        dp[a[1]][a[0]] = INT_MAX;
        //cout << a[0]  << ' ' << a[1]  <<'\n';
    }
    
    //dp[i][j] = i,j칸으로 오는 최단 경로의 수 = 상하좌우로 오는 최단 경로의 수 -> 위 또는 왼쪽으로 오는 경로의 수
    //dp[i][j] = dp[i-1][j] + dp[i][j];
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(dp[i][j] == INT_MAX) continue;
            if(dp[i-1][j] != INT_MAX){
                dp[i][j] += dp[i-1][j] % mod;
            }
            
            if(dp[i][j-1] != INT_MAX){
                dp[i][j] += dp[i][j-1] % mod;
            }
            
            dp[i][j] %= mod;
        }
    }
    
    answer = dp[n][m];
    return answer;
}