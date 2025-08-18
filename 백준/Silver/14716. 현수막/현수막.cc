#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <set>
using namespace std;

typedef long long ll;
vector<vector<int>> board;
vector<vector<bool>> visited;

int dy[8] = { -1,0,1,0 ,1,-1 ,-1 ,1};
int dx[8] = { 0,1,0,-1 ,1, 1, -1 ,-1};

int m, n;

void bfs(int by , int bx) {
    queue<pair<int, int>> q;
    q.push({ by,bx });
    visited[by][bx] = true;

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;

        q.pop();
        for (int i = 0; i < 8; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (0 > ny || ny >= m || 0 > nx || nx >= n)continue;
            if (visited[ny][nx] || board[ny][nx] == 0) continue;

            q.push({ ny,nx });
            visited[ny][nx] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);


    cin >> m >> n;

    board.resize(m, vector<int>(n));
    visited.resize(m, vector<bool>(n,false));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    int cnt = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 1 && !visited[i][j]) {
                bfs(i, j); 
                cnt++;
            }

        }
    }

    cout << cnt << '\n';
    return 0;
}