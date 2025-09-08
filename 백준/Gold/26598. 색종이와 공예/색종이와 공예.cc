#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <cstring>

using namespace std;

typedef long long ll;
typedef long double ld;

int n, m;
vector<vector<bool>> visited;
vector<vector<char>> board;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,-1,0,1 };


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    cin >> n >> m;
    visited.assign(n, vector<bool>(m));
    board.assign(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            board[i][j] = s[j];
        }

    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j] == false) {

                visited[i][j] = true;
                char target = board[i][j];
                queue<pair<int, int>> q;
                q.push({ i,j });
                int area = 1;

                pair<int, int> min = { i,j }; //왼쪽아래 모서리
                pair<int, int> max = { i,j }; //오른쪽 위 모서리

                while (!q.empty()) {
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();

                    for (int i = 0; i < 4; i++) {
                        int ny = y + dy[i];
                        int nx = x + dx[i];

                        if (0 > ny || ny >= n || 0 > nx || nx >= m) continue;
                        if (board[ny][nx] != target) continue;
                        if (visited[ny][nx]) continue;

                        q.push({ ny,nx });
                        area++;
                        visited[ny][nx] = true;

                        if (min.first < ny ) {
                            min.first = ny;
                        }
                        if (max.first > ny ) {
                            max.first = ny;
                        }
                        if ( min.second > nx) {
                            min.second = nx;
                        }
                        if ( max.second < nx) {
                            max.second = nx;
                        }


                    }

                }

                int xDiff = abs(min.second - max.second);
                int yDiff = abs(min.first - max.first);
  /*              cout << min.first << " " << min.second << '\n';
                cout << max.first << " " << max.second << '\n';
                cout << xDiff << " " << yDiff << '\n';
                cout << "area : " << area << '\n';
                cout << '\n';*/

                if (area != (xDiff+1) * (yDiff+1)) {
                    cout << "BaboBabo" << '\n';
                    return 0;
                }


            }
        }
    }

    cout << "dd" << '\n';

    return 0;
}