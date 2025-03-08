#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Skill {
    int x, y; // x: 기본 마나, y: 피해량
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;
    vector<Skill> skills(N);
    for (int i = 0; i < N; i++) {
        cin >> skills[i].x >> skills[i].y;
    }

    const int INF = 1e9;  // 충분히 큰 값
    // dp[d] : d만큼의 피해를 주기 위한 최소 마나 비용
    vector<int> dp(M + 1, INF);
    dp[0] = 0;

    // 각 스킬에 대해 dp를 갱신 (각 스킬은 한 그룹으로 처리)
    for (int i = 0; i < N; i++) {
        vector<int> new_dp(M + 1, INF);
        for (int d = 0; d <= M; d++) {
            if (dp[d] == INF) continue;
            // 스킬 i를 t번 사용 (t = 0일 때는 사용하지 않는 경우)
            // d + t * skills[i].y 가 M 이하인 경우에 대해서만 고려
            for (int t = 0; d + t * skills[i].y <= M; t++) {
                // t번 사용 시 총 비용 = t * x + K * (t-1)*t/2
                int cost = t * skills[i].x + (t * (t - 1) / 2) * K;
                int new_damage = d + t * skills[i].y;
                new_dp[new_damage] = min(new_dp[new_damage], dp[d] + cost);
            }
        }
        dp = new_dp;
    }

    cout << dp[M] << "\n";
    return 0;
}
