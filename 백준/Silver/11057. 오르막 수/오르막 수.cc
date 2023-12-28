#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> dp(N + 1, vector<int>(10, 0));

    // 길이가 1인 오르막 수 초기화
    for (int j = 0; j < 10; j++) {
        dp[1][j] = 1;
    }

    // 동적 프로그래밍을 사용하여 테이블 채우기
    for (int i = 2; i <= N; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = j; k < 10; k++) {
                dp[i][j] += dp[i - 1][k];
                dp[i][j] %= 10007; // 모듈러 연산 적용
            }
        }
    }

    int result = 0;
    for (int j = 0; j < 10; j++) {
        result += dp[N][j];
        result %= 10007; // 최종 결과에도 모듈러 연산 적용
    }

    cout << result << endl;

    return 0;
}
