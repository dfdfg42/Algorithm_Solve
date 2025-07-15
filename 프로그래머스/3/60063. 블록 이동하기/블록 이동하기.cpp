#include <vector>
#include <queue>
#include <climits>
#include <array>  
using namespace std;


int n;                                           
vector<vector<int>> g_board;                       
vector<vector<array<int,2>>> dist;                  

int dy[4] = {-1, 1, 0, 0};
int dx[4] = { 0, 0,-1, 1};

struct Drone {
    int y, x, dir;    
};

bool isFree(int y, int x) {
    return y>=0 && y<n && x>=0 && x<n && g_board[y][x]==0;
}

int solution(vector<vector<int>> board) {
    n = board.size();
    g_board = board;
    dist.assign(n, vector<array<int,2>>(n, {INT_MAX, INT_MAX}));
    
    queue<Drone> q;
    dist[0][0][0] = 0;
    q.push({0, 0, 0});
    
    while (!q.empty()) {
        auto cur = q.front(); 
        q.pop();
        
        int y = cur.y, x = cur.x, dir = cur.dir;
        int d = dist[y][x][dir];
        int y1 = y,       x1 = x;
        int y2 = y + dir, x2 = x + (dir==0);
        
        if ((y1==n-1 && x1==n-1) || (y2==n-1 && x2==n-1))
            return d;
        
        for (int i = 0; i < 4; i++) {
            int ny1 = y1 + dy[i], nx1 = x1 + dx[i];
            int ny2 = y2 + dy[i], nx2 = x2 + dx[i];
            if (isFree(ny1,nx1) && isFree(ny2,nx2)) {
                int ny = y + dy[i], nx = x + dx[i];
                if (dist[ny][nx][dir] > d + 1) {
                    dist[ny][nx][dir] = d + 1;
                    q.push({ny, nx, dir});
                }
            }
        }
        
        if (dir == 0) {
            if (y-1 >= 0 && isFree(y-1,x1) && isFree(y-1,x2)) {
                if (dist[y-1][x1][1] > d+1) {
                    dist[y-1][x1][1] = d+1;
                    q.push({y-1, x1, 1});
                }
                if (dist[y-1][x2][1] > d+1) {
                    dist[y-1][x2][1] = d+1;
                    q.push({y-1, x2, 1});
                }
            }
            if (y+1 < n && isFree(y+1,x1) && isFree(y+1,x2)) {
                if (dist[y][x1][1] > d+1) {
                    dist[y][x1][1] = d+1;
                    q.push({y, x1, 1});
                }
                if (dist[y][x2][1] > d+1) {
                    dist[y][x2][1] = d+1;
                    q.push({y, x2, 1});
                }
            }
        }
        else {

            if (x-1 >= 0 && isFree(y1,x-1) && isFree(y2,x-1)) {
                if (dist[y1][x-1][0] > d+1) {
                    dist[y1][x-1][0] = d+1;
                    q.push({y1, x-1, 0});
                }
                if (dist[y2][x-1][0] > d+1) {
                    dist[y2][x-1][0] = d+1;
                    q.push({y2, x-1, 0});
                }
            }
            if (x+1 < n && isFree(y1,x+1) && isFree(y2,x+1)) {
                if (dist[y1][x][0] > d+1) {
                    dist[y1][x][0] = d+1;
                    q.push({y1, x, 0});
                }

                if (dist[y2][x][0] > d+1) {
                    dist[y2][x][0] = d+1;
                    q.push({y2, x, 0});
                }
            }
        }
    }
    
    return -1;
}
