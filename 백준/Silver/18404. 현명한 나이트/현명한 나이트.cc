#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <cstring>
#include <set>
#include <cmath>
#include <climits>

using namespace std;

typedef long long ll;
typedef long double ld;

int dy[8] = { -1,-2,-2,-1,1,2,2,1 };
int dx[8] = { -2,-1,1,2,2,1,-1,-2 };

int n,m;

vector<vector<int>> visited;
vector<pair<int, int>> enemies;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    visited.resize(n + 1, vector<int>(n + 1, INT_MAX));
    
    int iy, ix;
    cin >> iy >> ix;
    queue<pair<int, int>> q;
    q.push({ iy,ix });
    visited[iy][ix] = 0;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        enemies.push_back({ a,b });
    }

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;

        q.pop();

        for (int i = 0; i < 8; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (1 > ny || ny > n || 1 > nx || nx > n)continue;
            if (visited[ny][nx] != INT_MAX) continue;

            q.push({ ny,nx });
            visited[ny][nx] = visited[y][x] + 1;

        }
    }

    for (auto& a : enemies) {
        cout << visited[a.first][a.second] << ' ';
    }

    return 0;
}