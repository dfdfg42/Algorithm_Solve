#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> castle;
vector<vector<bool>> visited;
vector<int> roomSizes;

int dx[4] = { 0,-1,0,1 }; // 서, 북, 동, 남
int dy[4] = { -1,0,1,0 };

int n, m;

// 벽이 있는지 확인하는 함수
bool hasWall(int x, int y, int direction) {
    return (castle[x][y] & (1 << direction)) != 0;
}

// BFS로 방을 탐색하고, 방의 크기를 반환하는 함수
int bfs(int startX, int startY) {
    queue<pair<int, int>> q;
    q.push({ startX, startY });
    visited[startX][startY] = true;

    int roomSize = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        roomSize++;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < m && ny < n && !visited[nx][ny]) {
                if (!hasWall(x, y, i)) {  // 벽이 없으면 이동
                    visited[nx][ny] = true;
                    q.push({ nx, ny });
                }
            }
        }
    }

    return roomSize;
}

int main() {
    cin >> n >> m;

    castle.resize(m, vector<int>(n));
    visited.resize(m, vector<bool>(n, false));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> castle[i][j];
        }
    }

    int roomCount = 0;
    int largestRoom = 0;

    // 1. 방의 개수와 가장 큰 방의 넓이를 계산
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                int roomSize = bfs(i, j);
                roomSizes.push_back(roomSize);
                roomCount++;
                largestRoom = max(largestRoom, roomSize);
            }
        }
    }

    int largestRoomWithRemovedWall = 0;

    // 2. 벽을 하나씩 제거하며 가장 넓은 방의 크기를 계산
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 4; k++) {  // 모든 방향의 벽에 대해 체크
                int nx = i + dx[k];
                int ny = j + dy[k];

                if (nx >= 0 && ny >= 0 && nx < m && ny < n && hasWall(i, j, k)) {
                    // 벽을 제거했을 때, 합쳐진 방의 크기 계산
                    fill(visited.begin(), visited.end(), vector<bool>(n, false));
                    castle[i][j] -= (1 << k);  // 벽 제거
                    int mergedRoomSize = bfs(i, j);
                    largestRoomWithRemovedWall = max(largestRoomWithRemovedWall, mergedRoomSize);
                    castle[i][j] += (1 << k);  // 원래대로 벽 복원
                }
            }
        }
    }

    cout << roomCount << '\n' << largestRoom << '\n' << largestRoomWithRemovedWall << '\n';

    return 0;
}
