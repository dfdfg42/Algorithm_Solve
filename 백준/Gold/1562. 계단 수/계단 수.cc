#include <iostream>
#include <cstring> // memset 함수 사용을 위해
using namespace std;

const int MOD = 1000000000;
int dp[101][10][1 << 10]; // [길이][마지막 숫자][사용된 숫자들의 비트마스크]

int main() {
    int N;
    cin >> N;

    // dp 배열 0으로 초기화
    memset(dp, 0, sizeof(dp));

    // 초기 조건 설정
    for (int i = 1; i <= 9; i++) {
        dp[1][i][1 << i] = 1;
    }

    // dp 배열 채우기
    for (int n = 2; n <= N; n++) {
        for (int last_digit = 0; last_digit <= 9; last_digit++) {
            for (int used_digits = 0; used_digits < (1 << 10); used_digits++) {
                if (last_digit > 0) {
                    dp[n][last_digit][used_digits | (1 << last_digit)] += dp[n - 1][last_digit - 1][used_digits];
                    dp[n][last_digit][used_digits | (1 << last_digit)] %= MOD;
                }
                if (last_digit < 9) {
                    dp[n][last_digit][used_digits | (1 << last_digit)] += dp[n - 1][last_digit + 1][used_digits];
                    dp[n][last_digit][used_digits | (1 << last_digit)] %= MOD;
                }
            }
        }
    }

    // 결과 계산
    int result = 0;
    for (int last_digit = 0; last_digit <= 9; last_digit++) {
        result = (result + dp[N][last_digit][(1 << 10) - 1]) % MOD;
    }

    // 결과 출력
    cout << result << endl;

    return 0;
}
