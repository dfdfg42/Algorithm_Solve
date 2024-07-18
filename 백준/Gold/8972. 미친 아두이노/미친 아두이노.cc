#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;

int dx[9] = { -1, 0, 1, -1, 0, 1, -1, 0, 1 };
int dy[9] = { 1, 1, 1, 0, 0, 0, -1, -1, -1 };

vector<vector<char>> world;
pair<int, int> jong;
vector<pair<int, int>> robots;
int r, c;
int moveCount;

bool boundary(int y, int x) {
    return (0 <= y && y < r && 0 <= x && x < c);
}

bool moveJong(int input) {
    int ny = jong.first + dy[input];
    int nx = jong.second + dx[input];

    if (world[ny][nx] == 'R') {
        cout << "kraj " << moveCount + 1 << '\n';
        return false;
    }
    else {
        world[jong.first][jong.second] = '.';
        jong = { ny, nx };
        world[ny][nx] = 'I';
        moveCount++;
        return true;
    }
}

void moveRobot() {
    vector<vector<int>> newPos(r, vector<int>(c, 0));
    vector<pair<int, int>> newRobots;

    for (auto& robot : robots) {
        int minDist = 1e9;
        int bestY = robot.first, bestX = robot.second;

        for (int i = 0; i < 9; i++) {
            int ny = robot.first + dy[i];
            int nx = robot.second + dx[i];
            if (boundary(ny, nx)) {
                int dist = abs(ny - jong.first) + abs(nx - jong.second);
                if (dist < minDist) {
                    minDist = dist;
                    bestY = ny;
                    bestX = nx;
                }
            }
        }

        if (world[bestY][bestX] == 'I') {
            cout << "kraj " << moveCount << '\n';
            exit(0);
        }
        newPos[bestY][bestX]++;
        newRobots.push_back({ bestY, bestX });
    }

    robots.clear();
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (newPos[i][j] == 1) {
                robots.push_back({ i, j });
                world[i][j] = 'R';
            }
            else if (newPos[i][j] > 1) {
                world[i][j] = '.';
            }
            else if (newPos[i][j] == 0) {
                world[i][j] = '.';
            }
        }
    }
    world[jong.first][jong.second] = 'I';
}

int main() {
    cin >> r >> c;
    world.resize(r, vector<char>(c));

    for (int i = 0; i < r; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < c; j++) {
            world[i][j] = s[j];
            if (s[j] == 'I') {
                jong = { i, j };
            }
            else if (s[j] == 'R') {
                robots.push_back({ i, j });
            }
        }
    }

    string command;
    cin >> command;
    moveCount = 0;

    for (char cmd : command) {
        if (!moveJong(cmd - '1')) {
            return 0;
        }
        moveRobot();
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << world[i][j];
        }
        cout << '\n';
    }

    return 0;
}
