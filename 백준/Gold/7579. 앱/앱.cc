#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;

    vector<ll> memory(N), cost(N);

    for (int i = 0; i < N; i++) {
        cin >> memory[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> cost[i];
    }

    ll maxCost = 100 * N; // 최대 비용
    vector<ll> dp(maxCost+1, 0); // 비용에 따른 메모리 최대치 저장

    for (int i = 0; i < N; i++) {
        for (int j = maxCost; j >= cost[i]; j--) {
            dp[j] = max(dp[j], dp[j-cost[i]] + memory[i]);
        }
    }

    // 필요한 메모리 M 바이트를 확보하기 위한 최소 비용을 찾기
    ll answer = maxCost;
    for (int i = 0; i <= maxCost; i++) {
        if (dp[i] >= M) {
            answer = i;
            break;
        }
    }

    cout << answer << endl;

    return 0;
}
