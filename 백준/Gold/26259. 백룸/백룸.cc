#include <iostream>
#include <vector>
#include <string>
#include <cstring> 
using namespace std;

static const long long NEG_INF = -1000000000000000000LL; 

bool blockDown[1001][1001];   
bool blockRight[1001][1001];  

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<long long>> arr(N, vector<long long>(M, 0LL));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    memset(blockDown, false, sizeof(blockDown));
    memset(blockRight, false, sizeof(blockRight));


    if (!(x1 == x2 && y1 == y2)) {
        if (x1 == x2) {
         
            int row = x1;
 
            if (row > 0 && row <= N) {
       
                int cStart = min(y1, y2);
                int cEnd = max(y1, y2);

                for (int c = cStart; c < cEnd; c++) {
                    if (0 <= c && c < M) {
                        blockDown[row - 1][c] = true;
                    }
                }
            }
        }
        else if (y1 == y2) {

            int col = y1;
  
            if (col > 0 && col <= M) {
                int rStart = min(x1, x2);
                int rEnd = max(x1, x2);
                for (int r = rStart; r < rEnd; r++) {
                    if (0 <= r && r < N) {
                        blockRight[r][col - 1] = true;
                    }
                }
            }
        }
    }

    vector<vector<long long>> dp(N, vector<long long>(M, NEG_INF));
    dp[0][0] = arr[0][0];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i == 0 && j == 0) continue;  

            if (i > 0 && dp[i - 1][j] != NEG_INF && !blockDown[i - 1][j]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + arr[i][j]);
            }

            if (j > 0 && dp[i][j - 1] != NEG_INF && !blockRight[i][j - 1]) {
                dp[i][j] = max(dp[i][j], dp[i][j - 1] + arr[i][j]);
            }
        }
    }

    long long answer = dp[N - 1][M - 1];
    if (answer == NEG_INF) {
        cout << "Entity\n";
    }
    else {
        cout << answer << "\n";
    }

    return 0;
}