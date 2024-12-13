#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

int n;

bool checkLine(vector<vector<char>>& board, char c) {
    // c로 이루어진 3연속이 있는지 확인
    for (int i = 0; i < 3; i++) {
        // 행 체크
        if (board[i][0] == c && board[i][1] == c && board[i][2] == c) return true;
        // 열 체크
        if (board[0][i] == c && board[1][i] == c && board[2][i] == c) return true;
    }
    // 대각선 체크
    if (board[0][0] == c && board[1][1] == c && board[2][2] == c) return true;
    if (board[0][2] == c && board[1][1] == c && board[2][0] == c) return true;

    return false;
}

bool isValid(vector<vector<char>>& board) {
    int OCount = 0;
    int XCount = 0;
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            if (board[r][c] == 'O') OCount++;
            else if (board[r][c] == 'X') XCount++;
        }
    }

    // 말의 개수 조건
    if (!(XCount == OCount || XCount == OCount + 1)) {
        return false;
    }

    bool XWin = checkLine(board, 'X');
    bool OWin = checkLine(board, 'O');

    // 둘 다 이긴 경우
    if (XWin && OWin) {
        return false;
    }

    // X가 이긴 경우: XCount는 OCount + 1 이어야 함.
    if (XWin && (XCount != OCount + 1)) {
        return false;
    }

    // O가 이긴 경우: XCount == OCount 이어야 함.
    if (OWin && (XCount != OCount)) {
        return false;
    }

    // 승자가 없는 경우 말의 개수 조건은 이미 위에서 통과함.
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
    
        vector<vector<char>> board(3, vector<char>(3));
        for (int r = 0; r < 3; r++) {
            string input;
            cin >> input;
            for (int c = 0; c < 3; c++) {
                board[r][c] = input[c];
            }
        }

        cout << (isValid(board) ? "yes" : "no") << "\n";
    }

    return 0;
}
