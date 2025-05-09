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

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

vector<vector<int>> m;
vector<vector<ld>> dist;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ld v;
    int r, c;
    cin >> v >> r >> c;

    m.resize(r + 1, vector<int>(c + 1));
    dist.resize(r + 1, vector<ld>(c + 1,INT_MAX));
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> m[i][j];
        }
    }

    queue <pair<pair<ld,ld>, pair<int, int>>> q; //{시간,속도}, {x,y}

    q.push({ { 0,v }, { 1,1 } });
    dist[1][1] = 0;
    while (!q.empty()) {
        ld time = q.front().first.first;
        ld speed = q.front().first.second;

        int y = q.front().second.first;
        int x = q.front().second.second;

        q.pop();
        if (dist[y][x] < time) continue;

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (1 <= ny && ny <= r && 1 <= nx && nx <= c) {
                ld calTime = time + (1 / speed);
                if (dist[ny][nx] > calTime) {
                    dist[ny][nx] = calTime;
                    q.push({ { calTime, speed * powl(2, m[y][x] - m[ny][nx]) },{ny,nx} });
                }

            }

        }


    }



    cout << fixed <<  setprecision(2) << dist[r][c] << '\n';
}
