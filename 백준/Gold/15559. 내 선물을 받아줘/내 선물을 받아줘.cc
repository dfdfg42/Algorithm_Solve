#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, m;
vector<vector<char>> board;
vector<vector<int>> state;
// state: 0 = not visited, 1 = visiting, 2 = done

int presentCount;

int dmap(char dir) {
    if (dir == 'N') return 0;
    if (dir == 'S') return 1;
    if (dir == 'E') return 2;
    if (dir == 'W') return 3;
    return -1;
}


int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, 1,-1 };

void dfs(int y, int x) {
    state[y][x] = 1; 
    int dir = dmap(board[y][x]);
    int ny = y + dy[dir];
    int nx = x + dx[dir];

    if (state[ny][nx] == 0) {
        // 아직 방문 안한 칸이면 DFS 진행
        dfs(ny, nx);
    }
    else if (state[ny][nx] == 1) {
        // 현재 경로 상에 있는 노드를 다시 방문 → 사이클 발생
        presentCount++;
    }
    // 탐색 완료 처리
    state[y][x] = 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    board.resize(n, vector<char>(m));
    state.resize(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        for (int j = 0; j < m; j++) {
            board[i][j] = input[j];
        }
    }

    presentCount = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (state[i][j] == 0) {
                dfs(i, j);
            }
        }
    }

    cout << presentCount << "\n";
    return 0;
}
