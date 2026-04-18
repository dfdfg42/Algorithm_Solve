#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> tree;
vector<int> dp;

int solution(vector<vector<int>> triangle) {
    int n = triangle.size();
    vector<vector<int>> dp = triangle;
    
    for(int r = 1; r < n; r++) {
        for(int c = 0; c <= r; c++) {
            if(c == 0)       dp[r][c] = dp[r-1][c] + triangle[r][c];
            else if(c == r)  dp[r][c] = dp[r-1][c-1] + triangle[r][c];
            else             dp[r][c] = max(dp[r-1][c-1], dp[r-1][c]) + triangle[r][c];
        }
    }
    return *max_element(dp[n-1].begin(), dp[n-1].end());
}