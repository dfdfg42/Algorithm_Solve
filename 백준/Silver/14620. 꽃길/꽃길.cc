#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <string>
using namespace std;

typedef long long ll;


int n;
vector<vector<int>> board;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int ans;
void dfs(int index,int cost,vector<vector<int>> tempBoard) {

    if (index == 3) {
        ans = min(cost, ans);
        return;
    }

    for (int i = 2; i < n; i++) {
        for (int j = 2; j < n; j++) {
            
            bool can = true;
            for (int t = 0; t < 4; t++) {
                if (tempBoard[i + dy[t]][j + dx[t]] == 1) can = false; continue;
            }

            if (!can) continue;

            tempBoard[i][j] = 1;
            int plus = 0;
            plus += board[i][j];
            for (int k = 0; k < 4; k++) {
                plus+= board[i + dy[k]][j + dx[k]];
                tempBoard[i + dy[k]][j + dx[k]] = 1;
            }

            dfs(index + 1, cost + plus, tempBoard);

            tempBoard[i][j] = 0;
            for (int k = 0; k < 4; k++) {
                tempBoard[i + dy[k]][j + dx[k]] = 0;
            }

            
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

	cin >> n;
    board.resize(n + 1, vector<int>(n + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
        }
    }

    ans = INT_MAX;

    vector<vector<int>> temp(n + 1, vector<int>(n + 1, 0));
    dfs(0, 0, temp);

    cout << ans << '\n';

    
    return 0;
}
