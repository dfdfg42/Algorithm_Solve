#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int N, M;
int office[8][8];
vector<pair<int, int>> cctvs;
const int dx[4] = { 0, 1, 0, -1 }; // 동, 남, 서, 북
const int dy[4] = { 1, 0, -1, 0 };

void watch(int x, int y, int dir, vector<vector<int>>& map) {
    int nx = x, ny = y;
    while (true) {
        nx += dx[dir];
        ny += dy[dir];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M || map[nx][ny] == 6) break;
        if (map[nx][ny] == 0) map[nx][ny] = -1; // 감시 구역 표시
    }
}

int calculateBlindSpot(vector<vector<int>>& map) {
    int count = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (map[i][j] == 0) ++count;
    return count;
}

int simulate(vector<int> directions) {
    vector<vector<int>> map(N, vector<int>(M));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            map[i][j] = office[i][j];

    for (int i = 0; i < cctvs.size(); ++i) {
        int x = cctvs[i].first, y = cctvs[i].second;
        int type = office[x][y];
        int dir = directions[i];

        switch (type) {
        case 1:
            watch(x, y, dir, map);
            break;
        case 2:
            watch(x, y, dir, map);
            watch(x, y, (dir + 2) % 4, map);
            break;
        case 3:
            watch(x, y, dir, map);
            watch(x, y, (dir + 1) % 4, map);
            break;
        case 4:
            watch(x, y, dir, map);
            watch(x, y, (dir + 1) % 4, map);
            watch(x, y, (dir + 2) % 4, map);
            break;
        case 5:
            watch(x, y, 0, map);
            watch(x, y, 1, map);
            watch(x, y, 2, map);
            watch(x, y, 3, map);
            break;
        }
    }
    return calculateBlindSpot(map);
}

int dfs(int index, vector<int>& directions) {
    if (index == cctvs.size()) {
        return simulate(directions);
    }
    int minBlindSpot = INT_MAX;
    for (int i = 0; i < 4; ++i) {
        directions[index] = i;
        minBlindSpot = min(minBlindSpot, dfs(index + 1, directions));
    }
    return minBlindSpot;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> office[i][j];
            if (office[i][j] >= 1 && office[i][j] <= 5) {
                cctvs.push_back({ i, j });
            }
        }
    }

    vector<int> directions(cctvs.size());
    cout << dfs(0, directions) << endl;

    return 0;
}
