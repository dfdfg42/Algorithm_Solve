#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <climits>
using namespace std;

vector<vector<string>> board;

int N;
int b, i, n, g, o, x, y;
int ans;

// y개 조합하기
void dfs(int start ,vector<vector<int>> &allSel, vector<int> &selected , int total) {
    if (selected.size() == y) {
        allSel.push_back(selected);

        return;
    }

    for (int i = start; i < total; i++) {

        selected.push_back(i);
        dfs(i + 1, allSel, selected, total);
        selected.pop_back();
    }

    return;

}

vector<string> boardAdd(vector<int> selected) {
    vector<string> returnBoard(5, "OOOOO");  
    for (int a : selected) {
        for (int i = 0; i < 5; i++) {
            string line = board[a][i];
            for (int j = 0; j < 5; j++) {
                if (line[j] == 'X') {  
                    returnBoard[i][j] = 'X';
                }
            }
        }
    }
    return returnBoard;
}

int cntNeed(vector<string> board) {
    int cnt = 0;
    int cntB = 0, cntI_val = 0, cntN = 0, cntG = 0, cntO = 0;

    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 5; col++) {
            if (row == 2 && col == 2)
                continue;
            if (board[row][col] == 'X') {  
                if (col == 0) cntB++;
                else if (col == 1) cntI_val++;
                else if (col == 2) cntN++;
                else if (col == 3) cntG++;
                else if (col == 4) cntO++;
            }
        }
    }

    cnt += max(0, cntB - b);
    cnt += max(0, cntI_val - i);
    cnt += max(0, cntN - n);
    cnt += max(0, cntG - g);
    cnt += max(0, cntO - o);

    return cnt;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;



    while (N--) {
        cin >> b >> i >> n >> g >> o >> x >> y;
        board.clear();
        board.resize(x);
        for (int j = 0; j < 5; j++) {
            for (int i = 0; i < x; i++) {
                string s;
                cin >> s;

                board[i].push_back(s);
            }
        }

        ans = INT_MAX;

        vector<int> selected;
        vector<vector<int>> allSel;
        dfs(0, allSel, selected, x);

        for (auto a : allSel) {
            vector<string> newBoard = boardAdd(a);
            int cnt = cntNeed(newBoard);
            ans = min(ans, cnt);

        }

        cout << ans << '\n';
    }
   
    return 0;
}
