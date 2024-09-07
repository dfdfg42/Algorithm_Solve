#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int dy[4] = { 0,-1,0,1 };
int dx[4] = { -1,0,1,0 };

int n;
vector<vector<char>> rgb;
vector<vector<bool>> check;
int blindCount;
int nBlindCount;

void bfs(int y, int x, bool blind) {

    queue<pair<int, int>> q;
    q.push({ y,x });
    check[y][x] = true;

    char color = rgb[y][x];


    while (!q.empty() && !blind) {
        int y = q.front().first;
        int x = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (0<=nx && nx <n && 0<= ny && ny<n ) {

                if (check[ny][nx] == false) {
                    if (rgb[ny][nx] == color) {
                        q.push({ ny, nx });

                        check[ny][nx] = true;
                    }
                }


            }

        }

    }

    while (!q.empty() && blind) {
        int y = q.front().first;
        int x = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (0 <= nx && nx < n && 0 <= ny && ny < n) {

                if (check[ny][nx] == false) {
                    if (color == 'B' && rgb[ny][nx] == color) {
                        q.push({ ny, nx });

                        check[ny][nx] = true;
                    }
                    else if (color == 'R' || color == 'G') {
                        if (rgb[ny][nx] == 'R' || rgb[ny][nx] == 'G') {
                            q.push({ ny, nx });

                            check[ny][nx] = true;
                        }

                    }
                }



            }

        }

    }


}

int main() {
    cin >> n;

    rgb.resize(n, vector<char>(n));
    check.resize(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++) {
        string s; cin >> s;

        for (int j = 0; j < n; j++) {
            rgb[i][j] = s[j];

        }

    }

    blindCount = 0;
    nBlindCount = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (check[i][j] == false) {
                bfs(i, j, false);
                nBlindCount++;
            }

        }
    }

    check.assign(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (check[i][j] == false) {
                bfs(i, j, true);
                blindCount++;
            }


            
        }
    }

    cout << nBlindCount << ' ' << blindCount << '\n';

    return 0;
}
