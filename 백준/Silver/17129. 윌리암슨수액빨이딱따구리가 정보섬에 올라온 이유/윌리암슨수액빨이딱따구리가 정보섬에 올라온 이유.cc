#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <climits>
using namespace std;

typedef long long ll;

int n, m;
vector<vector<int>> board;
vector<vector<int>> visited;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

void solve() {

    cin >> n >> m;
    board.resize(n, vector<int>(m));
    visited.resize(n, vector<int>(m, INT_MAX));

    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++) {
            board[i][j] = s[j] - '0';
            if (board[i][j] == 2) {
                visited[i][j] = 0;
                q.push({ i,j });
            }
        }
    }

    int three = INT_MAX, four = INT_MAX, five = INT_MAX;

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (0 > ny || ny >= n || 0 > nx || nx >= m) continue;
            if (board[ny][nx] == 1) continue;
            if (visited[ny][nx] <= visited[y][x] + 1) continue;


            visited[ny][nx] = visited[y][x] + 1;
            if (board[ny][nx] == 3) three = visited[ny][nx];
            if (board[ny][nx] == 4) four = visited[ny][nx];
            if (board[ny][nx] == 5) five = visited[ny][nx];
            q.push({ ny,nx });

        }

    }

    int best = min(three, min(four, five)); 
    if (best == INT_MAX) {
        cout << "NIE\n";
    }
    else {
        cout << "TAK\n" << best << "\n";
    }


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
