#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

struct subj {
    int time = 0;
    int pri = 0;
};


int main() {

    int N;
    cin >> N;
    int K;
    cin >> K;

    vector<subj> subjs(K + 1);
    for (int i = 1; i <= K; i++) {

        cin >> subjs[i].pri;
        cin >> subjs[i].time;
    }

    vector<vector<int>> dp(K + 1, vector<int>(N + 1, 0));

    for (int i = 1; i <= K; i++) {
        for (int j = 1; j <= N; j++) {

            dp[i][j] = dp[i - 1][j];

            if (subjs[i].time <= j) {
                dp[i][j] = max(dp[i - 1][j] , dp[i - 1][j - subjs[i].time] + subjs[i].pri);
            }
            
        }

    }

    cout << dp[K][N] << '\n';



    return 0;
}
