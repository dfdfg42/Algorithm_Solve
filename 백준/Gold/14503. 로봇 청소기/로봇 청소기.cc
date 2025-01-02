#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int cleanCount;

vector<vector<int>> rooms;

int n, m;
int Rx, Ry, Rd;

bool isAllClear(int y,int x) {
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (0 <= ny && ny < n && 0 <= nx && nx < m) {
            if (rooms[ny][nx] == 0 ) {
                return false;
            }
        }
    }

    return true;
}

bool reverse() {
    int nd = (Rd + 2) % 4;
    int ny = Ry + dy[nd];
    int nx = Rx + dx[nd];

    if (0 <= ny && ny < n && 0 <= nx && nx < m) {
        if (rooms[ny][nx] != 1) {
            Ry = ny;
            Rx = nx;
            return true;
        }
        else {
            return false;
        }
    }
}

int main() {

    cleanCount = 0;

    cin >> n >> m;

    rooms.resize(n, vector<int>(m));

    cin >> Ry >> Rx >> Rd;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> rooms[i][j];
        }
    }

    while (true) {




        bool allCleared = isAllClear(Ry, Rx);

        if (rooms[Ry][Rx] == 0) {
            rooms[Ry][Rx] = 2;
            cleanCount++;
        }
        else if (allCleared) {
            //후진해야함
            if (reverse()) {}
            else {
                cout << cleanCount << '\n';
                return 0;
            }

        }
        else if (!allCleared) {
            //회전하고 전진한다.
            Rd = (Rd + 3) % 4;
            
            int ny = Ry + dy[Rd];
            int nx = Rx + dx[Rd];

            if (0 <= ny && ny < n && 0 <= nx && nx < m) {
                if (rooms[ny][nx] == 0) {
                    Ry = ny;
                    Rx = nx;
                }
            }
        }

    }

    return 0;
}