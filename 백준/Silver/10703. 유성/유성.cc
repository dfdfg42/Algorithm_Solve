#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int r, s;
    cin >> r >> s;

    vector<vector<char>> board(r, vector<char>(s));
    for (int i = 0; i < r; i++) {
        string input;
        cin >> input;
        for (int j = 0; j < s; j++) {
            board[i][j] = input[j];
        }
    }

    int minDiff = INT_MAX;

    // 각 열마다 유성의 최하단과 땅의 최상단을 찾아 최소 차이를 구함
    for (int i = 0; i < s; i++) {
        int maxMeteor = -1;
        int minGround = INT_MAX;

        for (int j = 0; j < r; j++) {
            if (board[j][i] == 'X') {
                maxMeteor = j;
            }
            if (board[j][i] == '#' && minGround == INT_MAX) {
                minGround = j;
            }
        }
        
        // 유성이 있고, 그 아래에 땅이 있는 경우만 계산
        if (maxMeteor != -1 && minGround != INT_MAX) {
            minDiff = min(minGround - maxMeteor - 1, minDiff);
        }
    }

    // minDiff 만큼 유성을 아래로 내림
    vector<vector<char>> newBoard(r, vector<char>(s, '.'));

    for (int i = r - 1; i >= 0; i--) {
        for (int j = 0; j < s; j++) {
            if (board[i][j] == 'X') {
                newBoard[i + minDiff][j] = 'X';
            }
            if (board[i][j] == '#') {
                newBoard[i][j] = '#';
            }
        }
    }

    // 결과 출력
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < s; j++) {
            cout << newBoard[i][j];
        }
        cout << '\n';
    }

    return 0;
}
