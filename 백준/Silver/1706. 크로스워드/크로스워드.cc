#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int r, c;
    cin >> r >> c;

    vector<string> board(r);
    for (int i = 0; i < r; i++) {
        cin >> board[i];
    }

    vector<string> words;

    // 가로 낱말 추출
    for (int i = 0; i < r; i++) {
        string temp = "";
        for (int j = 0; j < c; j++) {
            if (board[i][j] == '#') {
                if (temp.length() >= 2) {
                    words.push_back(temp);
                }
                temp = "";
            }
            else {
                temp += board[i][j];
            }
        }
        if (temp.length() >= 2) {  // 행의 끝 처리
            words.push_back(temp);
        }
    }

    // 세로 낱말 추출
    for (int j = 0; j < c; j++) {
        string temp = "";
        for (int i = 0; i < r; i++) {
            if (board[i][j] == '#') {
                if (temp.length() >= 2) {
                    words.push_back(temp);
                }
                temp = "";
            }
            else {
                temp += board[i][j];
            }
        }
        if (temp.length() >= 2) {  // 열의 끝 처리
            words.push_back(temp);
        }
    }

    sort(words.begin(), words.end());
    cout << words[0] << "\n";

    return 0;
}
