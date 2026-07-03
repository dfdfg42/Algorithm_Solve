#include <string>
#include <vector>
#include <set>

using namespace std;

const int INF = 987654321;

int solution(int N, int number) {
    int answer = 0;
    
    vector<set<int>> dp(9);
   
    for(int i=1; i<=8; i++){
        
        long long repeated = 0;
        for (int k = 0; k < i; k++)
            repeated = repeated * 10 + N;
        dp[i].insert((int)repeated);
        
        for (int j = 1; j < i; j++) {
            for (int a : dp[j]) {
                for (int b : dp[i - j]) {
                    dp[i].insert(a + b);
                    dp[i].insert(a - b);
                    dp[i].insert(a * b);
                    if (b != 0) dp[i].insert(a / b);
                }
            }
        }

        if (dp[i].count(number)) return i;
        
    }
    
    return -1;
}