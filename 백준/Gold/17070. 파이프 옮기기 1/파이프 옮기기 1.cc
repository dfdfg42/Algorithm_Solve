#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> house;
long long dp[17][17][3];

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    house.assign(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> house[i][j];
        }
    }

    dp[0][1][0] = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 2; j < N; j++) { 
            if (house[i][j] == 1) {
                continue; 
            }

            dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][2];

            if (i > 0) {
                dp[i][j][1] = dp[i - 1][j][1] + dp[i - 1][j][2];
            }

            if (i > 0 && house[i - 1][j] == 0 && house[i][j - 1] == 0) {
                dp[i][j][2] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
            }
        }
    }


    long long result = dp[N - 1][N - 1][0] + dp[N - 1][N - 1][1] + dp[N - 1][N - 1][2];

    cout << result << endl;

    return 0;
}