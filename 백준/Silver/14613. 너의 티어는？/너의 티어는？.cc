#include <iostream>
#include <vector>
#include <iomanip> // setprecision을 사용하기 위해 필요합니다.

using namespace std;

typedef long double ld;

// dp[게임 수][승리 수][패배 수]
ld dp[21][21][21];
ld w, l, d;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> w >> l >> d;

    // 초기값: 0게임, 0승, 0패일 확률은 1
    dp[0][0][0] = 1.0;

    // DP 테이블 채우기
    for (int i = 1; i <= 20; i++) {       // 총 20경기
        for (int j = 0; j <= i; j++) {   // 승리 횟수 (0 ~ i)
            for (int k = 0; k <= i - j; k++) { // 패배 횟수 (0 ~ i-j)

                // 1. (i-1)경기에서 (j-1)승 k패였고, 이번에 이긴 경우
                if (j > 0) {
                    dp[i][j][k] += dp[i - 1][j - 1][k] * w;
                }

                // 2. (i-1)경기에서 j승 (k-1)패였고, 이번에 진 경우
                if (k > 0) {
                    dp[i][j][k] += dp[i - 1][j][k - 1] * l;
                }

                // 3. (i-1)경기에서 j승 k패였고, 이번에 비긴 경우
                // 무승부 횟수: (i-1) - j - k >= 0 이어야 함
                if (i - 1 >= j + k) {
                    dp[i][j][k] += dp[i - 1][j][k] * d;
                }
            }
        }
    }

    // 최종 티어별 확률 계산
    ld tier_probs[5] = { 0.0 }; // 0:브론즈, 1:실버, 2:골드, 3:플래티넘, 4:다이아

    for (int j = 0; j <= 20; j++) { // 최종 승리 수
        for (int k = 0; k <= 20 - j; k++) { // 최종 패배 수
            int score = 2000 + (j * 50) - (k * 50);

            if (score <= 1499) tier_probs[0] += dp[20][j][k];
            else if (score <= 1999) tier_probs[1] += dp[20][j][k];
            else if (score <= 2499) tier_probs[2] += dp[20][j][k];
            else if (score <= 2999) tier_probs[3] += dp[20][j][k];
            else if (score <= 3499) tier_probs[4] += dp[20][j][k];
        }
    }

    // 결과 출력
    cout << fixed << setprecision(8);
    for (int i = 0; i < 5; i++) {
        cout << tier_probs[i] << "\n";
    }

    return 0;
}