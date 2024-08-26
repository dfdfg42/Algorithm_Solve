#include <iostream>
using namespace std;

const int nm = 101;
int dp[nm][nm][nm];

int max(int a, int b, int c) {
    return max(max(a, b), c);
}

int main() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3; // 3개의 문자열 입력

    for (int i = 1; i <= s1.size(); i++) {
        for (int j = 1; j <= s2.size(); j++) {
            for (int k = 1; k <= s3.size(); k++) {
                if (s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1]) { // 3개 문자가 모두 같은 경우
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                } else { // 같지 않은 경우
                    dp[i][j][k] = max(dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]);
                }
            }
        }
    }
    cout << dp[s1.size()][s2.size()][s3.size()];

    return 0;
}
