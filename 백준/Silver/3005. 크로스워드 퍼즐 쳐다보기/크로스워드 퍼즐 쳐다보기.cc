#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int R, C;
    cin >> R >> C;
    vector<vector<char>> board(R, vector<char>(C));

    // 입력
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> board[i][j];
        }
    }

    vector<string> candidates;

    for (int i = 0; i < R; i++) {
        string temp;
        for (int j = 0; j < C; j++) {
            if (board[i][j] == '#') {
                if (temp.size() >= 2) candidates.push_back(temp);
                temp.clear();
            }
            else {
                temp.push_back(board[i][j]);
            }
        }
        if (temp.size() >= 2) candidates.push_back(temp);
    }


    for (int j = 0; j < C; j++) {
        string temp;
        for (int i = 0; i < R; i++) {
            if (board[i][j] == '#') {
                if (temp.size() >= 2) candidates.push_back(temp);
                temp.clear();
            }
            else {
                temp.push_back(board[i][j]);
            }
        }
        if (temp.size() >= 2) candidates.push_back(temp);
    }


    sort(candidates.begin(), candidates.end());
    cout << candidates.front() << "\n";

    return 0;
}
