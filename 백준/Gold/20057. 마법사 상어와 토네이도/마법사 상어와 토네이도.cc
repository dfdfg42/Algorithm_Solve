#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>

using namespace std;

typedef long long ll;
int n;

vector<vector<int>> board;
pair<int, int > tornado;
int delta; //토네이도 이동량
int dir; //토네이도 방향
int lostSand; //잃어버린 모래양

int dy[4] = { 0,1,0,-1 };
int dx[4] = { -1,0,1,0 };

bool check(int a,int b) {
    if (a >= n || a < 0 || b >= n || b < 0) {
        return false;
    }
    return true;
}

int cal(int y,int x,int sand, float ratio) {
    int temp = floor((float)sand * ratio);

    if (check(y, x) == false) {
        lostSand += temp;
        return -temp;
    }


    board[y][x] += temp;

    return -temp;
}

void moveSand(int y, int x,int sand) {
    int temp = sand;
    if (dir == 0) { //왼쪽
        temp += cal(y - 1, x, sand, 0.07);
        temp += cal(y + 1, x, sand, 0.07);
        temp += cal(y + 2, x, sand, 0.02);
        temp += cal(y - 2, x, sand, 0.02);
        temp += cal(y + 1, x-1, sand, 0.1);
        temp += cal(y - 1, x-1, sand, 0.1);
        temp += cal(y , x-2, sand, 0.05);
        temp += cal(y + 1, x+1, sand, 0.01);
        temp += cal(y - 1, x+1, sand, 0.01);
    }
    else if (dir == 1) { // 아래
        temp += cal(y - 1, x + 1, sand, 0.01);
        temp += cal(y - 1, x - 1, sand, 0.01);
        temp += cal(y, x + 1, sand, 0.07);
        temp += cal(y, x - 1, sand, 0.07);
        temp += cal(y, x + 2, sand, 0.02);
        temp += cal(y, x - 2, sand, 0.02);
        temp += cal(y + 1, x + 1, sand, 0.1);
        temp += cal(y + 1, x - 1, sand, 0.1);
        temp += cal(y + 2, x, sand, 0.05);
    }
    else if (dir == 2) { //오른쪽
        temp += cal(y + 1, x, sand, 0.07);
        temp += cal(y - 1, x, sand, 0.07);
        temp += cal(y - 2, x, sand, 0.02);
        temp += cal(y + 2, x, sand, 0.02);
        temp += cal(y + 1, x-1, sand, 0.01);
        temp += cal(y - 1, x-1, sand, 0.01);
        temp += cal(y + 1, x +1, sand, 0.1);
        temp += cal(y -1 , x +1, sand, 0.1);
        temp += cal(y , x +2, sand, 0.05);
    }
    else if (dir == 3) { //위
        temp += cal(y + 1, x - 1, sand, 0.01);
        temp += cal(y + 1, x + 1, sand, 0.01);
        temp += cal(y, x + 1, sand, 0.07);
        temp += cal(y, x - 1, sand, 0.07);
        temp += cal(y - 1, x + 1, sand, 0.1);
        temp += cal(y - 1, x -1, sand, 0.1);
        temp += cal(y - 2, x, sand, 0.05);
        temp += cal(y, x + 2, sand, 0.02);
        temp += cal(y, x - 2, sand, 0.02);
        
    }


    if (check(y +dy[dir], x + dx[dir]) == false) {
        lostSand += temp;
    }
    else {
        board[y + dy[dir]][x + dx[dir]] += temp;
    }
    board[y][x] = 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    cin >> n;
    board.resize(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    tornado.first = n / 2;
    tornado.second = n / 2 ;
    //cout << tornado.first << ' ' << tornado.second << '\n';
    int delta = 1;
    int cnt = 0;
    dir = 0;
    lostSand = 0;
    //토네이도 이동
    while (true) {
        
        int ny = tornado.first + dy[dir] * delta;
        int nx = tornado.second + dx[dir] * delta;
        //cout << "delta : " << delta  << " dir : " << dir << '\n';
        //cout << ny << ' ' << nx << '\n';

        while (tornado.first != ny || tornado.second != nx) {
            //cout << "tornado : " << tornado.first << ' ' << tornado.second << '\n';
            tornado.first += dy[dir];
            tornado.second += dx[dir];
            if (tornado.first >= n || tornado.first < 0 || tornado.second >= n || tornado.second < 0) break;
            moveSand(tornado.first ,tornado.second ,board[tornado.first][tornado.second]);



        }

        if (ny >= n || ny < 0 || nx >= n || nx < 0) break;

        dir = dir + 1;
        dir %= 4;
        cnt++;
        if (cnt % 2 == 0) {
            delta += 1;
        }

    }

    cout << lostSand << '\n';

    return 0;
}