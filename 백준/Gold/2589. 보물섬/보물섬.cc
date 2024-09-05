
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;

int dy[4] = { 0,1,0,-1 };
int dx[4] = { -1,0,1,0 };
vector<vector<char>> tMap;
int maxDist;

int bfs(int inputY, int inputX) {
    //좌표,거리
    queue<pair<int, int>> q;
    vector<vector<int>> dist(n, vector<int>(m, -1));

    q.push({ inputY,inputX });
    dist[inputY][inputX] = 0;
    int mdist = 0;

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0 <= nx && nx < m && 0 <= ny && ny < n) {
                if (tMap[ny][nx] == 'L') {
                    if (dist[ny][nx] == -1 || dist[ny][nx] > dist[y][x] + 1) {
                        q.push({ ny,nx });
                        dist[ny][nx] = dist[y][x] + 1;
                    }
                }
            }
        }

    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            mdist = max(mdist, dist[i][j]);
        }
    }

 /*   for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }

    cout << '\n';*/
    return mdist;
}

int main()
{

    cin >> n >> m;

    tMap.resize(n, vector<char>(m));
    maxDist = 0;

    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;

        for (int j = 0; j < m; j++) {
            tMap[i][j] = input[j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (tMap[i][j] == 'L') {
                maxDist = max(bfs(i, j), maxDist);
            }
        }
    }

    cout << maxDist << '\n';

}