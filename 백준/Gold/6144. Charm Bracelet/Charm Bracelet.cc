#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    int n, m;
    cin >> n >> m;

    vector<int> dp(m + 1, 0);
    vector<vector<int>> jew(n + 1, vector<int>(2));

    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b; // 무게, 가치

        jew[i][0] = a;  // 무게
        jew[i][1] = b;  // 가치
    }

    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= jew[i][0]; j--) {  // 역순으로 무게 처리
            dp[j] = max(dp[j], dp[j - jew[i][0]] + jew[i][1]);  // 최대 가치 선택
        }
    }

    cout << dp[m];

    return 0;
}
