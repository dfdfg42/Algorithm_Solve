#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[1001][1001] = { 0, };

int main() {

    string s1, s2;
    cin >> s1 >> s2;  // Read the strings from user input

    // The outer loop should start from 1 to length of s1
    // The inner loop should start from 1 to length of s2
    for (int i = 1; i <= s1.length(); i++) {
        for (int j = 1; j <= s2.length(); j++) {
            if (s1[i - 1] == s2[j - 1]) {  // Adjust index for 0-based string index
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);  // Correct the indices
            }
        }
    }
    cout << dp[s1.length()][s2.length()];
    
    return 0;
}
