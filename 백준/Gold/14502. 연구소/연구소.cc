#include <iostream>
#include <vector>
#include <iomanip> 
#include <queue>

using namespace std;

typedef long double ld;
typedef long long ll;

vector<vector<int>> board;
int n, m;
int safePlace;
int ans = 0;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    cin >> n >> m;
    board.resize(n, vector<int>(m));
    safePlace = n * m;
    ans = 0;
    vector<pair<int, int>> virus;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) {
                virus.push_back({ i, j });
                safePlace--;
            }
            if (board[i][j] == 1)safePlace--;
        }
    }
    //cout << safePlace << '\n';

    for (int i = 0; i < n*m; i++) {
        for (int j = 0; j < n * m; j++) {
            for (int k = 0; k < n * m; k++) {
				if (i == j || j == k || i == k) continue;
				if (board[i / m][i % m] == 1 || board[j / m][j % m] == 1 || board[k / m][k % m] == 1) continue;
                if (board[i / m][i % m] == 2 || board[j / m][j % m] == 2 || board[k / m][k % m] == 2) continue;

                board[i / m][i % m] = 1;
				board[j / m][j % m] = 1;
                board[k / m][k % m] = 1;

				vector<vector<int>> temp = board;
                int tempSafePlace = safePlace - 3;
                queue<pair<int, int>> q;
                for (auto v : virus) {
                    temp[v.first][v.second] = 2;
                    q.push({ v.first,v.second });
                }


                while (!q.empty()) {
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();

                    for (int t = 0; t < 4; t++) {
                        int ny = y + dy[t];
                        int nx = x + dx[t];

                        if (0 > ny || ny >= n || 0 > nx || nx >= m) continue;
                        if (temp[ny][nx] == 1 || temp[ny][nx] == 2) continue;

                        temp[ny][nx] = 2;
                        tempSafePlace--;
                        q.push({ ny,nx });
                    }

                }
                board[i / m][i % m] = 0;
                board[j / m][j % m] = 0;
                board[k / m][k % m] = 0;

                //cout << "=============\n";
                //for (int o = 0; o < n; o++) {
                //    for (int p = 0; p < m; p++) {
                //        cout << temp[o][p] <<' ';
                //    }
                //    cout << '\n';
                //}
                ans = max(ans, tempSafePlace);
                //cout << "tempSafePlace: " << tempSafePlace << '\n';
            }
        }
        
    }
    cout << ans << '\n';

    return 0;
}