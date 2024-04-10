#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;

int maze[100][100];
int check[100][100] = { false };
int dist[100][100];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1,-1,0,0 };
queue<pair <int, int>> q;

void findWay(queue<pair<int,int>> q) {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) {
                if (check[nx][ny] == false && maze[nx][ny] == 1) {
                    q.push(make_pair(nx, ny));
                    dist[nx][ny] = dist[x][y] + 1;
                    check[nx][ny] = true;
                }
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string input; cin >> input;
        for (int j = 0; j < m; j++) {
            if (input[j] == '1') {
                maze[i][j] = 1;
            }
            else {
                maze[i][j] = 0;
            }
        }
    }

    q.push(make_pair(0, 0));
    check[0][0] = true;
    dist[0][0] = 1;

    findWay(q);
    
    cout << dist[n-1][m-1];

    return 0;
}
