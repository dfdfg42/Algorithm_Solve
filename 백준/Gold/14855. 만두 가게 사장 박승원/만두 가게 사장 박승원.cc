#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Dumpling {
    int a, b, c, d;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, c0, d0;
    cin >> n >> m >> c0 >> d0;
    vector<Dumpling> dumplings(m + 1);
    vector<int> cnt(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> dumplings[i].a >> dumplings[i].b >> dumplings[i].c >> dumplings[i].d;
        cnt[i] = dumplings[i].a / dumplings[i].b; // 해당 만두 최대 개수
    }

    // dp[j]: j그램 밀가루 사용 시 최대 금액
    vector<int> dp(n + 1, 0);

    // 먼저 스페셜 만두(무제한)를 처리
    for (int j = c0; j <= n; j++) {
        dp[j] = max(dp[j], dp[j - c0] + d0);
    }

    for (int i = 1; i <= m; i++) {

        for (int j = n; j >= 0; j--) {
            for (int k = 1; k <= cnt[i]; k++) {
                int cost = k * dumplings[i].c;
                if (j >= cost) {
                    dp[j] = max(dp[j], dp[j - cost] + k * dumplings[i].d);
                }
                else {
                    break;
                }
            }
        }

        for (int j = c0; j <= n; j++) {
            dp[j] = max(dp[j], dp[j - c0] + d0);
        }
    }

    cout << dp[n] << '\n';
    return 0;
}
