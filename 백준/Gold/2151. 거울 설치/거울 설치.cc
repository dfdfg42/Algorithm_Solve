#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <algorithm>
#include <string>
#include <iomanip> 
#include <queue>
#include <cmath>
using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 987654321;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

vector<vector<char>> m;
vector<vector<int>> dist;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    dist.resize(n + 1, vector<int>(n + 1, INT_MAX));
    m.resize(n + 1, vector<char>(n + 1));
    vector<pair<int, int>> point;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++) {
           // cout << i << j << '\n';
             m[i][j] = s[j];
             if (m[i][j] == '#') {
                 point.push_back({ i,j });
             }
        }
    }

    queue < pair<int, pair<int, int>>> q; //횟수 , y,x;
    q.push({ 0, { point[0].first,point[0].second } });
    dist[point[0].first][point[0].second] = 0;

    while (!q.empty()) {
        int c = q.front().first;
        int y = q.front().second.first;
        int x = q.front().second.second;
        q.pop();

        if (c > dist[y][x]) continue;

        for (int dir = 0; dir < 4; dir++) {
            int ny = y, nx = x;

            while (true) {
                ny += dy[dir];
                nx += dx[dir];


                if (ny < 0 || ny >= n || nx < 0 || nx >= n || m[ny][nx] == '*') {
                    break;
                }

    
                if (m[ny][nx] == '#') {
                    if (c < dist[ny][nx]) {
                        dist[ny][nx] = c;
                        q.push({ c+1, {ny, nx} });
                    }
                    break;
                }


                if (m[ny][nx] == '!') {
                    if (c + 1 < dist[ny][nx]) {
                        dist[ny][nx] = c + 1;
                        q.push({ c+1, {ny, nx} });
                    }
                }

            }
        }

    }
    cout << dist[point[1].first][point[1].second] << '\n';

    
    
    return 0;
}
