#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;


typedef long long ll;
int n, m , k;
int x, y;
vector<vector<int>> board;
vector<vector<int>> dice;

int dy[4] = { 0,0,-1,1 };
int dx[4] = { 1,-1,0,0 };

void moveRight() {
    vector<vector<int>> temp(4, vector<int>(3));
    temp[0][1] = dice[0][1];
    temp[1][0] = dice[3][1];
    temp[1][1] = dice[1][0];
    temp[1][2] = dice[1][1];
    temp[2][1] = dice[2][1];
    temp[3][1] = dice[1][2];
    dice = temp;
}

void moveLeft() {
    vector<vector<int>> temp(4, vector<int>(3));
    temp[0][1] = dice[0][1];
    temp[1][0] = dice[1][1];
    temp[1][1] = dice[1][2];
    temp[1][2] = dice[3][1];
    temp[2][1] = dice[2][1];
    temp[3][1] = dice[1][0];
    dice = temp;
}

void moveUp() {
    vector<vector<int>> temp(4, vector<int>(3));
    temp[0][1] = dice[3][1];
    temp[1][0] = dice[1][0];
    temp[1][1] = dice[0][1];
    temp[1][2] = dice[1][2];
    temp[2][1] = dice[1][1];
    temp[3][1] = dice[2][1];
    dice = temp;

}

void moveDown() {
    vector<vector<int>> temp(4, vector<int>(3));

    temp[0][1] = dice[1][1];
    temp[1][0] = dice[1][0];
    temp[1][1] = dice[2][1];
    temp[1][2] = dice[1][2];
    temp[2][1] = dice[3][1];
    temp[3][1] = dice[0][1];
    dice = temp;
}

void checkDice() {
    int& upside = dice[1][1];
    int& downside = dice[3][1];
    if (board[y][x] == 0) {
        board[y][x] = downside;
    }
    else {
        downside = board[y][x];
        board[y][x] = 0;
    }
    cout << upside << '\n';
}

void showDice() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << dice[i][j];
        }
        cout << endl;
    }
    cout << endl << '\n';
}

void tmp() {
    dice[0][1] = 2;
    dice[1][0] = 4;
    dice[1][1] = 1;
    dice[1][2] = 3;
    dice[2][1] = 5;
    dice[3][1] = 6;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    dice.resize(4, vector<int>(3,0));



    cin >> n >> m >> y >> x >> k;

    board.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }



    

    for (int i = 0; i < k; i++) {
        int dir;
        cin >> dir;

        int ny = y + dy[dir - 1];
        int nx = x + dx[dir - 1];
        if (ny < 0 || ny >= n ||  nx < 0 || nx >= m) continue;
        y = ny;
        x = nx;

        if (dir == 1) {
            moveRight();
            checkDice();
        }
        else if (dir == 2) {
            moveLeft();
            checkDice();
        }
        else if (dir == 3) {
            moveUp();
            checkDice();
        }
        else if (dir == 4) {
            moveDown();
            checkDice();
        }
        
    }


    return 0;
}