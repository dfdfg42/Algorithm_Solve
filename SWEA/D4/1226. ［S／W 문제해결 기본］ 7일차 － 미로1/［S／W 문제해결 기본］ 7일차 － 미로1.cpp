#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for (int tc = 1; tc <= 10; tc++) {
        int t; cin >> t;

        vector<vector<int>> maze(16, vector<int>(16, -1));
        vector<vector<bool>> visited(16, vector<bool>(16, false));
        pair<int, int> start;
        pair<int, int > end;
        
        for (int i = 0; i < 16; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < 16; j++) {
                maze[i][j] = s[j] - '0';
                if (s[j] - '0' == 2) {
                    start = { i,j };
                }
            }
        }

        queue<pair<int, int>> q;
        q.push(start);
        visited[start.first][start.second] = true;
        bool goal = false;

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;

            if (maze[x][y] == 3) {
                goal = true;
                break;
            }

            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (0 <= nx && nx < 16 && 0 <= ny && ny < 16 && maze[nx][ny] != 1) {
                    if (!visited[nx][ny]) {
                        visited[nx][ny] = true;
                        q.push({ nx,ny });

                    }
                }

            }

        }

        if (goal) {
            cout << '#' << tc << ' ' << 1 << '\n';
        }
        else {
            cout << '#' << tc << ' ' << 0 << '\n';
        }


    }


    return 0;
}
