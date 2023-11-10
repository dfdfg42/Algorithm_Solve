#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int shortest_path(vector<vector<int>>& map, int N, int M) {
    vector<vector<vector<int>>> visited(2, vector<vector<int>>(N, vector<int>(M, 0)));
    queue<tuple<int, int, int>> q;

    q.push(make_tuple(0, 0, 0)); // (x, y, 벽을 부순 횟수)
    visited[0][0][0] = 1;

    while (!q.empty()) {
        int x, y, wall;
        tie(x, y, wall) = q.front();
        q.pop();

        if (x == N - 1 && y == M - 1) {
            return visited[wall][x][y];
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
                if (map[nx][ny] == 0 && visited[wall][nx][ny] == 0) {
                    visited[wall][nx][ny] = visited[wall][x][y] + 1;
                    q.push(make_tuple(nx, ny, wall));
                }
                else if (map[nx][ny] == 1 && wall == 0 && visited[1][nx][ny] == 0) {
                    visited[1][nx][ny] = visited[wall][x][y] + 1;
                    q.push(make_tuple(nx, ny, 1));
                }
            }
        }
    }

    return -1;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> map(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < M; j++) {
            map[i][j] = line[j] - '0';
        }
    }

    cout << shortest_path(map, N, M) << endl;

    return 0;
}
