#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N;

    vector<int> sequences(N+1);
    for(int i = 1; i <= N; ++i) {
        cin >> sequences[i];
    }

    vector<vector<int>> dp(N+1, vector<int>(N+1, 0));

    // 길이가 1인 경우
    for(int i = 1; i <= N; ++i) {
        dp[i][i] = 1;
    }

    // 길이가 2인 경우
    for(int i = 1; i <= N-1; ++i) {
        if(sequences[i] == sequences[i+1]) {
            dp[i][i+1] = 1;
        }
    }

    // 길이가 3 이상인 경우
    for(int length = 3; length <= N; ++length) {
        for(int start = 1; start <= N-length+1; ++start) {
            int end = start + length - 1;
            if(sequences[start] == sequences[end] && dp[start+1][end-1]) {
                dp[start][end] = 1;
            }
        }
    }

    cin >> M;
    for(int i = 0; i < M; ++i) {
        int S, E;
        cin >> S >> E;
        cout << dp[S][E] << '\n';
    }

    return 0;
}
