#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<long long> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    vector<pair<int, long long>> dp(N);

    int answer = 1; 
    for (int i = 0; i < N; i++) {
        
        dp[i] = { 1, a[i] };

        for (int j = 0; j < i; j++) {
            if (dp[j].second >= a[i]) {
  
                if (dp[j].first + 1 > dp[i].first) {
                    dp[i].first = dp[j].first + 1;
                    dp[i].second = dp[j].second + a[i];
                }
            
                else if (dp[j].first + 1 == dp[i].first) {
                    dp[i].second = max(dp[i].second, dp[j].second + a[i]);
                }
            }
        }
        answer = max(answer, dp[i].first);
    }

    cout << answer << "\n";
    return 0;
}
