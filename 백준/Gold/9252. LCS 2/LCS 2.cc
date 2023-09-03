#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string input1;
string input2;

void findAns(int i, int j, vector<vector<int>>& dp) {
    if (i == 0 || j == 0) return; // Base case
    if (input1[i - 1] == input2[j - 1]) {
        findAns(i - 1, j - 1, dp);
        cout << input1[i - 1];
    }
    else {
        if (dp[i - 1][j] > dp[i][j - 1]) {
            findAns(i - 1, j, dp);
        }
        else {
            findAns(i, j - 1, dp);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> input1 >> input2;

    int n = input1.size();
    int m = input2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (input1[i - 1] == input2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[n][m] << endl;

    findAns(n, m, dp); // 출력 함수 호출

    return 0;
}
