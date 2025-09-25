#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;


int n, q;
int l;

int boardSize;
vector<vector<int>> board;
int totalIce;
int bigOne;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void showBoard() {
    cout << '\n';
    for (int i = 0; i < pow(2,n); i++) {
        for (int j = 0; j < pow(2, n); j++) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}

bool check(int a, int b) {
    if (a < 0 || a >= boardSize || b < 0 || b >= boardSize) return false;

    return true;
}

void rot(int range) {

    vector<vector<int>> temp(boardSize, vector<int>(boardSize));


    for (int i = 0; i < boardSize; i += range) {
        for (int j = 0; j < boardSize; j += range) {


            for (int k = 0; k < range; k++) {
                for (int t = 0; t < range; t++) {

                    temp[i + k][j + t] = board[i + range - 1 - t][j + k];
                }
            }
        }
    }

    board = temp;
}

void melt() {

    vector<vector<int>> temp = board;

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {

            int cnt = 0;
            for (int t = 0; t < 4; t++) {
                int ny = i + dy[t];
                int nx = j + dx[t];

                if (check(ny, nx) && board[ny][nx] > 0) {
                    cnt++;
                }
            }

            if (cnt < 3) {
                temp[i][j] = max(board[i][j] - 1,0);
            }
            else   temp[i][j] = board[i][j];

        }
    }

    board = temp;
}

void cal() {
    vector<vector<bool>> visited(boardSize, vector<bool>(boardSize, false));

    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            if (visited[i][j] || board[i][j] <=0) continue;

            int iceSize = 1;
            totalIce += board[i][j];
            queue<pair<int, int>> q;
            q.push({ i,j });
            
            visited[i][j] = true;

            while (!q.empty()) {
                int y = q.front().first;
                int x = q.front().second;
                q.pop();

                for (int t = 0; t < 4; t++) {
                    int ny = y + dy[t];
                    int nx = x + dx[t];

                    if (!check(ny, nx)) continue;
                    if (visited[ny][nx]) continue;
                    if (board[ny][nx] <= 0) continue;

                    q.push({ ny,nx });
                    visited[ny][nx] = true;
                    iceSize += 1;
                    totalIce += board[ny][nx];
                }

            }
            bigOne = max(iceSize, bigOne);
        }
    }



}

void fireStorm() {

    rot(pow(2,l));

    //showBoard();

    melt();

    //showBoard();
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> q;
    board.resize(pow(2,n), vector<int>(pow(2, n)));
    boardSize = 1 << n;
    for (int i = 0; i < pow(2, n); i++) {
        for (int j = 0; j < pow(2, n); j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < q; i++) {
        cin >> l;
        fireStorm();
    }


    //남아있는 얼음의 합
    //얼음중 가장 큰 덩어리가 차지하는 칸의 개수
    totalIce = 0;
    bigOne = 0;
    cal();
    cout << totalIce << '\n';
    cout << bigOne << '\n';

    return 0;
}