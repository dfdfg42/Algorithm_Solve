#include <vector>
#include <queue>
using namespace std;

static int S(int v) { return v << 1; } // 좌표 2배

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    const int N = 105;
    vector<vector<int>> board(N, vector<int>(N, 0));
    vector<vector<int>> dist(N, vector<int>(N, -1));


    for (int i = 0; i < (int)rectangle.size(); ++i) {
        const vector<int>& r = rectangle[i];
        int x1 = S(r[0]), y1 = S(r[1]), x2 = S(r[2]), y2 = S(r[3]);
        for (int y = y1; y <= y2; ++y)
            for (int x = x1; x <= x2; ++x)
                board[y][x] = 1;
    }

    for (int i = 0; i < (int)rectangle.size(); ++i) {
        const vector<int>& r = rectangle[i];
        int x1 = S(r[0]), y1 = S(r[1]), x2 = S(r[2]), y2 = S(r[3]);
        for (int y = y1 + 1; y < y2; ++y)
            for (int x = x1 + 1; x < x2; ++x)
                board[y][x] = 0; // 내부 막기
    }

    int sy = S(characterY), sx = S(characterX);
    int ty = S(itemY), tx = S(itemX);

    queue<pair<int,int>> q;
    q.push(pair<int,int>(sy, sx));
    dist[sy][sx] = 0;

    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, 1, 0, -1};

    while (!q.empty()) {
        pair<int,int> p = q.front(); q.pop();
        int y = p.first, x = p.second;
        if (y == ty && x == tx) break;

        for (int d = 0; d < 4; ++d) {
            int ny = y + dy[d], nx = x + dx[d];
            if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
            if (board[ny][nx] != 1) continue;  
            if (dist[ny][nx] != -1) continue;
            dist[ny][nx] = dist[y][x] + 1;
            q.push(pair<int,int>(ny, nx));
        }
    }

    return dist[ty][tx] / 2; 
}
