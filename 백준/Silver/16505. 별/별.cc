#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>
using namespace std;

vector<vector<char>> board;

void print(int size, int y,int x ) {


    if (size == 1) {
        board[y][x] = '*';
        return;
    }

    size /= 2;
    print(size, y, x);
    print(size, y, x + size);
    print(size, y + size, x);

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int s = 1 << n;
    board.resize(s, vector<char>(s, ' '));
    print(s,0,0);
    for (int i = 0; i < s; i++) {
        int last_star_pos = -1;
        for (int j = 0; j < s; j++) {
            if (board[i][j] == '*') {
                last_star_pos = j;
            }
        }

        if (last_star_pos != -1) {
            for (int j = 0; j <= last_star_pos; j++) {
                cout << board[i][j];
            }
        }
        cout << '\n';
    }
    return 0;
}