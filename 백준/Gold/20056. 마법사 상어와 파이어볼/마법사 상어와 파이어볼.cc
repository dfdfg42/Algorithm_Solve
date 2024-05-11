#include <iostream>
#include <vector>
#include <queue>
#include <climits>

#define MAX 52
using namespace std;

struct fireBall {
    int y;
    int x;
    int mass;
    int speed;
    int dir;
};

int N, M, K;
vector<fireBall> mapVec[MAX][MAX];

int dx[8] = { 0,1,1,1,0,-1,-1,-1 };
int dy[8] = { -1,-1,0,1,1,1,0,-1 };

// 경계 조정 함수
int isBoundary(int x) {
    if (x > N) {
        x = x % N;
    }
    if (x < 1) {
        x = N + (x % N);
    }

    return x;
}

void moveFireBall() {
    vector<fireBall> temp[MAX][MAX];

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (mapVec[i][j].size() == 0) {
                continue;
            }
            else {
                for (int k = 0; k < mapVec[i][j].size(); k++) {
                    int mass = mapVec[i][j][k].mass;
                    int speed = mapVec[i][j][k].speed;
                    int dir = mapVec[i][j][k].dir;
                    int ny = isBoundary(dy[dir] * speed + mapVec[i][j][k].y);
                    int nx = isBoundary(dx[dir] * speed + mapVec[i][j][k].x);

                    temp[ny][nx].push_back({ ny,nx,mass,speed,dir });
                }

            }
        }
    }

    // 격자 상태 업데이트
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            mapVec[i][j] = temp[i][j];
        }
    }
}

void sumFireBall() {
    vector<fireBall> temp[MAX][MAX];

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (mapVec[i][j].size() == 0) {
                continue;
            }
            else if (mapVec[i][j].size() == 1) {
                temp[i][j] = mapVec[i][j];
            }
            else {
                int sumMass = 0;
                int sumSpeed = 0;
                bool sameDir = true; 
                for (int t = 0; t < mapVec[i][j].size(); t++) {
                    sumMass += mapVec[i][j][t].mass;
                    sumSpeed += mapVec[i][j][t].speed;
                    
                    if (t > 0 && mapVec[i][j][t].dir % 2 != mapVec[i][j][t - 1].dir % 2) {
                        sameDir = false;
                    }
                }

                sumMass /= 5;
                sumSpeed /= mapVec[i][j].size();

                if (sumMass == 0) {
                    continue; 
                }

                for (int d = 0; d < 4; d++) {
                    if (sameDir) {
                        temp[i][j].push_back({ i, j, sumMass, sumSpeed, d * 2 });
                    }
                    else {
                        temp[i][j].push_back({ i, j, sumMass, sumSpeed, d * 2 + 1 });
                    }
                }
            }
        }
    }

    
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            mapVec[i][j] = temp[i][j];
        }
    }
}

int main() {
    cin >> N >> M >> K;

    for (int i = 0; i < M; i++) {
        int y, x, m, s, d;
        cin >> y >> x >> m >> s >> d;
        mapVec[x][y].push_back({ y,x,m,s,d });
    }

    for (int i = 0; i < K; i++) {
        moveFireBall();
        sumFireBall();
    }

    int result = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 0; k < mapVec[i][j].size(); k++) {
                result += mapVec[i][j][k].mass;
            }
        }
    }

    cout << result << '\n';

    return 0;
}
