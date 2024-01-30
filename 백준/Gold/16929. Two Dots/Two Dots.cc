#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<char>> dots;
vector<vector<bool>> visited;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };

bool dfs(int x, int y, int fromX, int fromY, char color) {
    if (visited[x][y]) {
        return true; // 사이클이 존재합니다.
    }

    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
            if (dots[nx][ny] == color && (nx != fromX || ny != fromY)) {
                if (dfs(nx, ny, x, y, color)) {
                    return true;
                }
            }
        }
    }

    return false;
}

int main() {
    cin >> N >> M;
    dots = vector<vector<char>>(N, vector<char>(M));
    visited = vector<vector<bool>>(N, vector<bool>(M, false));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> dots[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visited[i][j]) {
                if (dfs(i, j, -1, -1, dots[i][j])) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "No" << endl;
    return 0;
}
