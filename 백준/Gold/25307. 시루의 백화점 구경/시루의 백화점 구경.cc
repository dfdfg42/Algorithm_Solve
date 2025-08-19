#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

vector<vector<int>> board;
vector<vector<int>> visited;
int n, m,k;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    board.resize(n, vector<int>(m));
    visited.resize(n, vector<int>(m, INT_MAX));
    vector<vector<bool>>unsafe(n, vector<bool>(m, false));

    queue<pair<pair<int, int>,int>> maneking;
    queue<pair<int, int>> q;
    pair<int, int> end = { -1,-1 };
    pair<int, int> start = { -1,-1 };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 3) {
                maneking.push({ {i,j},0 });
                unsafe[i][j] = true;
                visited[i][j] = 0;
            }
            if (board[i][j] == 4) {
                q.push({ i,j });
                start = { i,j };
            }
            if (board[i][j] == 2) {
                end = { i,j };
            }
        }
    }

    if (end.first == -1 && end.second == -1) {
        cout << -1 << '\n';
        return 0;
    }
    if (start.first == -1 && start.second == -1) {
        cout << -1 << '\n';
        return 0;
    }

    
    while (!maneking.empty()) {
        int y = maneking.front().first.first;
        int x = maneking.front().first.second;
        //cout << y << ' ' << x << '\n';
        int dist = maneking.front().second;
        maneking.pop();
        
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (0 > ny || ny >= n || 0 > nx || nx >= m) continue;
            if (unsafe[ny][nx]) continue;
            if (dist + 1 > k) continue;
            if (visited[ny][nx] <= visited[y][x] + 1) continue;

            visited[ny][nx] = visited[y][x] + 1;
            unsafe[ny][nx] = true;
            maneking.push({ { ny,nx },dist + 1 });

        }
    }


    //cout << '\n';
    //for (int i = 0; i < n; i++) {
    //    for (int j = 0; j < m; j++) {
    //        cout << unsafe[i][j] <<' ';
    //    }
    //    cout << '\n';
    //}

    visited.clear();
    visited.resize(n, vector<int>(m, INT_MAX));
    visited[start.first][start.second] = 0;

    int ans = INT_MAX;
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        if (board[y][x] == 2) {
            ans = min(ans, visited[y][x]);
        }
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if (0 > ny || ny >= n || 0 > nx || nx >= m) continue;
            if (unsafe[ny][nx]) continue;
            if (board[ny][nx] == 1) continue;
            if (visited[ny][nx] <= visited[y][x] + 1 || board[ny][nx] == 3) continue;

            visited[ny][nx] = visited[y][x] + 1;
            q.push({ ny,nx });

        }
    }

    //cout << endl << endl;
    //for (int i = 0; i < n; i++) {
    //    for (int j = 0; j < m; j++) {
    //        cout << (visited[i][j] == INT_MAX ? -1 : visited[i][j]) <<' ';
    //    }
    //    cout << '\n';
    //}

    if (visited[end.first][end.second] == INT_MAX) {
        cout << -1 << '\n';
    }
    else {
        cout << ans << '\n';
    }

    return 0;
}