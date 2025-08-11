#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int odd_dy[6] = { -1,-1,0,1,1,0 };
int odd_dx[6] = { 0,1,1,1,0,-1 };

int even_dy[6] = { -1,-1,0,1,1,0 };
int even_dx[6] = { -1,0,1,0,-1,-1 };

vector<vector<int>> board;
vector<vector<int>> dist;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    board.resize(n, vector<int>(m, 0));
    dist.resize(n, vector<int>(m, INT_MAX));
    
    //1 장애물 0 갈 수 있음
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> y >> x;
        board[y][x] = 1;
    }

    queue<pair<int, int>> q;
    q.push({ 0,0 });
    dist[0][0] = 0;

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;

        q.pop();

        for (int i = 0; i < 6; i++) {
            int ny, nx;
            if (y % 2 == 0) {
                 ny = y + even_dy[i];
                 nx = x + even_dx[i];
            }
            else {
                 ny = y + odd_dy[i];
                 nx = x + odd_dx[i];
            }


            if (0 > ny || ny >= n || 0 > nx || nx >= m) continue;
            if (board[ny][nx] == 1) continue;

            if (dist[ny][nx] > dist[y][x] + 1) {
                dist[ny][nx] = dist[y][x] + 1;
                q.push({ ny,nx });
            }
        }
    }
   

    if (dist[n - 1][m - 1] == INT_MAX) {
        cout << -1 << '\n';
    }
    else {
        cout << dist[n - 1][m - 1];
    }
}