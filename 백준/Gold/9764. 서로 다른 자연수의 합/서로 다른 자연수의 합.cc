#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
#define MOD 100999

int dp[2001][2001];

int main() {

    int t;
    int n;

    // dp[i][j] 1~j의 수들의 합으로 i 를 만드는 방법의수
    // 1. j를 포함하지 않고 만드는경우
    // dp[i][j-1];
    // 2. j를 포함해서 i를 만드는경우
    // if(i>=j)  D[i][j] = (D[i][j] + D[i-j][j-1]) % mod ; 
    // D[i-j][j-1] = i-j를 1 ~ j-1 사이의 수들로 만드는방법의 수 


    dp[0][0] = 1;
    for (int i = 1; i < 2001; i++) {
        dp[i][0] = 0;
        dp[0][i] = 1;
    }
    for (int i = 1; i < 2001; i++) {
        for (int j = 1; j < 2001; j++) {
            dp[i][j] = dp[i][j - 1];  //j를 포함하지 않고 i를 만드는 경우
            if (i >= j) {
                dp[i][j] += dp[i - j][j - 1];
                dp[i][j] %= MOD;
            }
        }
    }

    cin >> t;
    while (t--) {
        cin >> n;
        cout << dp[n][n] << endl;
    }


    return 0;
}
