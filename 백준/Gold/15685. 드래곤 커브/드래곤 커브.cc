#include <iostream>
#include <vector>
#include <cmath> // abs()를 위해 포함

using namespace std;

int n;

int dy[4] = { 0,-1,0,1 };
int dx[4] = { 1,0,-1,0 };

vector<vector<int>> board;
int ans;

//드래곤커브들의 방향구하기
void dragon(vector<int>& curves ,int g) {
    if (g == 0) {
        return;
    }
    for (int i = curves.size() - 1; i >= 0; i--) { //뒤에서부터 dy dx 한칸씩 밀어서 넣어주면됨
        curves.push_back((curves[i] + 1) % 4);
    }

    g--;
    dragon(curves, g);
}

void checkRect(int size) {
    for (int i = 0; i < 101 - size; i++) {
        for (int j = 0; j < 101 - size; j++) {
            if (board[i][j] == 1 && board[i + size][j] == 1
                && board[i][j + size] == 1 && board[i + size][j + size] == 1) {
                ans++;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    board.resize(101, vector<int>(101, 0));
    for (int i = 0; i < n; i++) {
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        vector<int> curves;
        curves.push_back(d);
        dragon(curves, g);


        board[y][x] = 1;
        int ny = y, nx = x;
        for (auto c : curves) {
            ny += dy[c];
            nx += dx[c];
            board[ny][nx] = 1;

        }


    }

    ans = 0;
    checkRect(1);
    cout << ans << '\n';

    return 0;
}