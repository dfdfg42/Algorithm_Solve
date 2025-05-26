#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <queue>
#include <cmath>
#include <climits>
using namespace std;

typedef long long ll;
typedef long double ld;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int n, m,t;
vector<vector<int>> board;
vector<vector<int>> dist;

int gran;
pair<int, int> granxy;

queue<pair<int, int>> q;

bool check(int y,int x) {
    if (1 <= y && y <= n && 1 <= x && x <= m) {
        return true;
    }
    else {
        return false;
    }
    return false;
}

void solve() {

    cin >> n >> m >> t;
    
    board.resize(n + 1, vector<int>(m + 1));
    dist.resize(n + 1, vector<int>(m + 1 , 123456789));



    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> board[i][j];
            
        }
    }


    q.push({1,1});
    dist[1][1] = 0;

    gran = 123456789;
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();


        //cout << " y " << y << " x " << x << '\n';


        if (board[y][x] == 2) {
            gran = dist[y][x];
            granxy.first = y;
            granxy.second = x;
        }

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (check(ny, nx)) {
                if (dist[ny][nx] == 123456789 && board[ny][nx] != 1) {

                    dist[ny][nx] = dist[y][x] + 1;
                    q.push( { ny,nx } );
                }
            }

        }

    }

    if(gran != 123456789)
    gran += abs(granxy.first - n) + abs(granxy.second - m);

    
    int ans = min(gran, dist[n][m]);

    if (ans <= t ) {
        cout << ans << '\n';
    }
    else  {
        cout << "Fail" << '\n';
    }
    //cout << gran << '\n';
    //cout << dist[n][m] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    solve();



    return 0;
}