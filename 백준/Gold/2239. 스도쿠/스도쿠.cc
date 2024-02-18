#include <iostream>
#include <vector>

using namespace std;

int board[9][9];

bool check(int row, int col, int num) {
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num) {
            return false;
        }
    }
    return true;
}

bool solveSudoku() {
    int row = -1, col = -1;
    bool isEmpty = true;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 0) {
                row = i;
                col = j;
                isEmpty = false;
                break;
            }
        }
        if (!isEmpty) {
            break;
        }
    }
    if (isEmpty) {
        return true;
    }
    for (int num = 1; num <= 9; num++) {
        if (check(row, col, num)) {
            board[row][col] = num;
            if (solveSudoku()) {
                return true;
            }
            board[row][col] = 0;
        }
    }
    return false;
}

int main() {
    for (int i = 0; i < 9; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < 9; j++) {
            board[i][j] = line[j] - '0'; // 문자를 숫자로 변환
        }
    }

    if (solveSudoku()) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << board[i][j];
            }
            cout << endl;
        }
    }
    else {
        cout << "No solution exists";
    }

    return 0;
}
