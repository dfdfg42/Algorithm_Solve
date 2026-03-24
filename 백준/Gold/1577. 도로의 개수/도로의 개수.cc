#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;

int N, M, K;
set<pair<pair<int,int>, pair<int,int>>> breaks;

bool isBreak(int x, int y, int bx, int by) {
    return breaks.count({{x,y},{bx,by}}) > 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    vector<vector<ll>> dp(N + 1, vector<ll>(M + 1, 0));
    cin >> K;
    
    for (int i = 0; i < K; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        breaks.insert({{a,b},{c,d}});
        breaks.insert({{c,d},{a,b}});
    }
    
    dp[0][0] = 1;
    
    for (int i = 1; i <= M; i++) {
        if (!isBreak(0, i, 0, i-1) && dp[0][i-1] != 0) {
            dp[0][i] = 1;
        }
    }
    
    for (int i = 1; i <= N; i++) {
        if (!isBreak(i, 0, i-1, 0) && dp[i-1][0] != 0) {
            dp[i][0] = 1;
        }
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (!isBreak(i, j, i-1, j)) {
                dp[i][j] += dp[i-1][j];
            }
            if (!isBreak(i, j, i, j-1)) {
                dp[i][j] += dp[i][j-1];
            }
        }
    }
    
    cout << dp[N][M] << '\n';
    
    return 0;
}