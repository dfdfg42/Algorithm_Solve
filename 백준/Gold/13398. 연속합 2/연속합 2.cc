#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> array(n);
    for (int i = 0; i < n; ++i) {
        cin >> array[i];
    }

    // 2차원 DP 배열 초기화
    vector<vector<int>> dp(n, vector<int>(2, 0));

    // 초기 조건 설정
    dp[0][0] = array[0];
    dp[0][1] = 0;
    int max_sum = array[0];

    // DP를 이용한 최대 부분 배열 합 계산
    for (int i = 1; i < n; ++i) {
        dp[i][0] = max(dp[i-1][0] + array[i], array[i]);
        dp[i][1] = max(dp[i-1][1] + array[i], dp[i-1][0]);
        max_sum = max({max_sum, dp[i][0], dp[i][1]});
    }

    cout << max_sum << endl;
    return 0;
}
