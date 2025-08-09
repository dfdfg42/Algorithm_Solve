#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long ll;

int r, c;
vector<vector<char>> m;
vector<vector<char>> vision;
vector<vector<bool>> g_visited;

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

void Init() {
    cin >> r >> c;
    m.resize(r, vector<char>(c));
    vision.resize(r, vector<char>(c, '#'));
    g_visited.resize(r, vector<bool>(c, false));

    for (int i = 0; i < r; i++) {
        string s;
        cin >> s; 
        for (int j = 0; j < s.length(); j++) {
            m[i][j] = s[j];
        }
    }
}

void bfs(int by, int bx){

    char target = m[by][bx];
    queue<pair<int, int>> q;
    q.push({ by,bx });

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        g_visited[y][x] = true;
        vision[y][x] = '.';
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (0 > ny || ny >= r || 0 > nx || nx >= c) continue;
            if (m[ny][nx] == target && !g_visited[ny][nx]) {
                q.push({ ny,nx });
                g_visited[ny][nx] = true;
            }

        }

    }

}

void solve() {

    Init();

    int Hr, Hc;
    cin >> Hr >> Hc;
    Hr -= 1;
    Hc -= 1;


    string record;
    cin >> record;


    for (int i = 0; i < record.length(); i++) {
        char now = record[i];

        if (now == 'U') {
            Hr -= 1;
        }
        else if (now == 'D') {
            Hr += 1;
        }
        else if (now == 'L') {
            Hc -= 1;
        }
        else if (now == 'R') {
            Hc += 1;
        }
        else if (now == 'W') {
            if(!g_visited[Hr][Hc])
            bfs(Hr, Hc);
        }
    }

    vision[Hr][Hc] = '.';
    //마지막위치에서 시야 확인
    for (int i = 0; i < 4; i++) {
        int ny = Hr + dy[i];
        int nx = Hc + dx[i];
        if (0 > ny || ny >= r || 0 > nx || nx >= c) continue;
        vision[ny][nx] = '.';
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << vision[i][j];
        }
        cout << '\n';
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
