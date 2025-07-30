#include <string>
#include <vector>
#include <climits>
#include <algorithm> 

using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems) {
    int max_alp = 0;
    int max_cop = 0;
    
    for (int i = 0; i < problems.size(); i++) {
        max_alp = max(max_alp, problems[i][0]);
        max_cop = max(max_cop, problems[i][1]);
    }
    

    alp = min(alp, max_alp);
    cop = min(cop, max_cop);
    

    vector<vector<int>> dp(max_alp + 31, vector<int>(max_cop + 31, INT_MAX));
    dp[alp][cop] = 0;
    
    for (int i = 0; i <= max_alp; i++) {
        for (int j = 0; j <= max_cop; j++) {
            if (dp[i][j] == INT_MAX) continue;
            
            int t = dp[i][j];
            // 알고리즘 공부
            if (i + 1 <= max_alp)
                dp[i + 1][j] = min(dp[i + 1][j], t + 1);
            // 코딩 공부
            if (j + 1 <= max_cop)
                dp[i][j + 1] = min(dp[i][j + 1], t + 1);
            
            // 문제 풀기
            for (int p = 0; p < problems.size(); p++) {
                if (i >= problems[p][0] && j >= problems[p][1]) {
                    int ni = min(max_alp, i + problems[p][2]);
                    int nj = min(max_cop, j + problems[p][3]);
                    dp[ni][nj] = min(dp[ni][nj], t + problems[p][4]);
                }
            }
        }
    }
    
    return dp[max_alp][max_cop];
}
