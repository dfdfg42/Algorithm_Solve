#include <iostream>
#include <vector>
using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int cheeseCount;
int n, m;
vector<vector<int>> world;
vector<vector<bool>> check;

bool boundary(int x, int y) {
    if (0 <= x && x < n && 0 <= y && y < m) return true;

    return false;
}

void findOx(int x, int y) {

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (boundary(nx, ny)) {
            if (world[nx][ny] == 0 && check[nx][ny] == false) {
                check[nx][ny] = true;
                findOx(nx, ny);
            }
        }

    }

}
void cheeseCheck() {
    vector<pair<int, int>> toMelt;

    for (int a = 0; a < n; a++) {
        for (int b = 0; b < m; b++) {
            if (world[a][b] == 1) {
                int oxCount = 0;
                for (int i = 0; i < 4; i++) {
                    int nx = a + dx[i];
                    int ny = b + dy[i];
                    if (boundary(nx, ny) && check[nx][ny]) {
                        oxCount++;
                    }
                }
                if (oxCount >= 2) {
                    toMelt.push_back({ a, b });
                }
            }
        }
    }

    for (auto& cell : toMelt) {
        world[cell.first][cell.second] = 0;
        cheeseCount--;
    }
}






int main() {
    //1. 일단 공기를 돌면서 치즈에 갖혀있는지 아닌지 판별한다
    // ->가장자리 공기를 탐색하고 외부 탐색이 안 되었다면 내부 공기
    //2.치즈를 녹이고 시간을 보낸후 치즈가 0개라면 시간 출력



    cin >> n >> m;
    world.resize(n, vector<int>(m,0));
 

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> world[i][j];
            if (world[i][j] == 1) cheeseCount++;
        }
    }

    int phase = 0;
    while (cheeseCount > 0) {
        check.assign(n, vector<bool>(m, false));
        //외부 공기 확인
        check[0][0] = true;
        findOx(0, 0);
        //접촉 치즈 확인
        cheeseCheck();
        
        phase++;
    }

    cout << phase << '\n';

    return 0;
}


