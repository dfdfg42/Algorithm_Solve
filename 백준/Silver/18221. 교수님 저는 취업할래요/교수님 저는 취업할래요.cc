#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

vector<vector<int>> board;
pair<int, int> prof, sung;
int n;

bool CountingStudents(int startRow, int endRow, int startCol, int endCol) {
    int count = 0;
    for (int i = startRow; i <= endRow; i++) { // 행(세로)
        for (int j = startCol; j <= endCol; j++) { // 열(가로)
            if (board[i][j] == 1) {
                count++;
            }
        }
    }
    return count >= 3;
}

int main() {
    cin >> n;
    board.resize(n, vector<int>(n));

    for (int i = 0; i < n; i++) { // 행(세로)
        for (int j = 0; j < n; j++) { // 열(가로)
            cin >> board[i][j];
            if (board[i][j] == 5) prof = {i, j};
            if (board[i][j] == 2) sung = {i, j};
        }
    }

    int distSquared = (prof.first - sung.first) * (prof.first - sung.first) +
                      (prof.second - sung.second) * (prof.second - sung.second);

    if (distSquared >= 25) {
        int startRow = min(prof.first, sung.first);
        int endRow = max(prof.first, sung.first);
        int startCol = min(prof.second, sung.second);
        int endCol = max(prof.second, sung.second);

        if (CountingStudents(startRow, endRow, startCol, endCol)) {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
    } else {
        cout << 0 << '\n';
    }

    return 0;
}
