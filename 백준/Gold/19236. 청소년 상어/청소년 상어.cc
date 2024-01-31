#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

const int dx[] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
const int dy[] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };

struct fish {
    int num;
    int dir;
    int x;
    int y;
};

struct shark {
    int dir;
    int x;
    int y;
    int points;
};


void moveFish(map<int, fish>& fishmap, shark& shark, vector<vector<int>>& grid) {
    for (int i = 1; i <= 16; i++) {
        if (fishmap.find(i) == fishmap.end()) continue; // 물고기가 이미 먹힌 경우

        fish& f = fishmap[i];
        for (int j = 0; j < 8; j++) {
            int nx = f.x + dx[f.dir];
            int ny = f.y + dy[f.dir];

            if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4 && !(nx == shark.x && ny == shark.y)) {
                if (grid[nx][ny] != -1) { // 다른 물고기와 위치 교환
                    fish& otherFish = fishmap[grid[nx][ny]];
                    swap(otherFish.x, f.x);
                    swap(otherFish.y, f.y);
                    swap(grid[otherFish.x][otherFish.y], grid[f.x][f.y]);
                }
                else { // 빈 공간으로 이동
                    grid[f.x][f.y] = -1;
                    f.x = nx;
                    f.y = ny;
                    grid[nx][ny] = f.num;
                }
                break;
            }

            // 방향 변경
            f.dir = f.dir + 1;
            if (f.dir > 8) f.dir = 1;
        }
    }
}


int maxScore = 0;  // 전역 변수로 최대 점수를 관리
void dfs(map<int, fish> fishmap, shark s, vector<vector<int>> grid, int score) {
    moveFish(fishmap, s, grid);
 

    bool canMove = false;  // 상어가 이동할 수 있는지 여부

    // 상어 이동 가능한 모든 칸 탐색
    for (int step = 1; step <= 3; step++) {
        int nx = s.x + dx[s.dir] * step;
        int ny = s.y + dy[s.dir] * step;

        if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4 && grid[nx][ny] != -1) {
            canMove = true;
            int num = grid[nx][ny];
            shark newShark = { fishmap[num].dir, nx, ny, score + num };

            map<int, fish> newFishMap = fishmap;
            vector<vector<int>> newGrid = grid;
            newFishMap.erase(num);
            newGrid[s.x][s.y] = -1;
            newGrid[nx][ny] = -1;

            dfs(newFishMap, newShark, newGrid, newShark.points);

        }
    }

    if (!canMove) {
        maxScore = max(maxScore, score);  // 이동할 수 없으면 현재 점수를 최대 점수와 비교
    }

}


int main() {
    vector<vector<int>> grid(4, vector<int>(4, -1));
    map<int, fish> fishmap;

    // 입력 받기
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int num, dir;
            cin >> num >> dir;
            grid[i][j] = num;
            fishmap[num] = { num, dir, i, j };
        }
    }

    // 상어 초기 위치 설정 및 첫 물고기 먹기
    shark s = { fishmap[grid[0][0]].dir, 0, 0, grid[0][0] };
    fishmap.erase(grid[0][0]);
    grid[0][0] = -1;


    // DFS를 사용한 탐색
    dfs(fishmap, s, grid, s.points);

    cout << maxScore << endl;

    return 0;
}