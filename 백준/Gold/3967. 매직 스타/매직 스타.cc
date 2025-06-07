#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

vector<vector<char>> board;
vector<vector<char>> result;
bool found = false;
map<int,bool> used;

pair<int, int> positions[12] = {
    {0,4}, {1,1}, {1,3}, {1,5}, {1,7},
    {2,2}, {2,6}, {3,1}, {3,3}, {3,5}, {3,7},
    {4,4}
};

int lines[6][4] = {
    {0, 2, 5, 7},
    {0, 3, 6, 10},
    {1, 2, 3, 4},
    {7, 8, 9, 10},
    {11, 8, 5, 1},
    {11, 9, 6, 4}
};

int getValue(int row, int col, const vector<vector<char>>& tBoard) {
    char c = tBoard[row][col];
    if (c >= 'A' && c <= 'L') return c - 'A' + 1;
    return 0;
}

int getLineSum(int li, const vector<vector<char>>& tBoard) {
    int sum = 0;
    for (int k = 0; k < 4; k++) {
        int pi = lines[li][k];
        int r = positions[pi].first;
        int c = positions[pi].second;
        sum += getValue(r, c, tBoard);
    }
    return sum;
}

bool check(const vector<vector<char>>& tBoard) {
    for (int i = 0; i < 6; i++)
        if (getLineSum(i, tBoard) != 26)
            return false;
    return true;
}

void dfs(const vector<int>& emptyPos, int idx, vector<vector<char>>& tBoard) {
    if (found) return;
    if (idx == emptyPos.size()) {
        if (check(tBoard)) {
            result = tBoard;
            found = true;
        }
        return;
    }

    int pi = emptyPos[idx];
    int r = positions[pi].first;
    int c = positions[pi].second;

    int must = -1;
    for (int li = 0; li < 6; li++) {
        bool inLine = false;
        int sum = 0, cntEmpty = 0;
        for (int k = 0; k < 4; k++) {
            int pj = lines[li][k];
            int rr = positions[pj].first;
            int cc = positions[pj].second;
            if (pj == pi) {
                inLine = true;
            } else if (tBoard[rr][cc] == 'x') {
                cntEmpty++;
            } else {
                sum += getValue(rr, cc, tBoard);
            }
        }
        if (inLine && cntEmpty == 0) {
            int need = 26 - sum;
            if (need < 1 || need > 12 || used[need]) return;
            if (must == -1) must = need;
            else if (must != need) return;
        }
    }

    auto place = [&](int num) {
        tBoard[r][c] = char('A' + num - 1);
        used[num] = true;
        dfs(emptyPos, idx + 1, tBoard);
        used[num] = false;
        tBoard[r][c] = 'x';
    };

    if (must != -1) {
        place(must);
    } else {
        for (int num = 1; num <= 12; num++) {
            if (!used[num]) {
                place(num);
                if (found) return;
            }
        }
    }
}


void solve() {
    board.resize(5, vector<char>(9));
    for (int i = 0; i < 5; i++) {
        string s; cin >> s;
        for (int j = 0; j < 9; j++) board[i][j] = s[j];
    }

    for (int n = 1; n <= 12; n++) used[n] = false;
    vector<int> emptyPositions;
    for (int i = 0; i < 12; i++) {
        int r = positions[i].first, c = positions[i].second;
        char ch = board[r][c];
        if (ch == 'x') {
            emptyPositions.push_back(i);        
        } else if ('A' <= ch && ch <= 'L') {
            used[ch - 'A' + 1] = true;         
        }
    }

    vector<vector<char>> tBoard = board;
    dfs(emptyPositions, 0, tBoard);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 9; j++) cout << result[i][j];
        cout << '\n';
    }
}

/* main() 동일 */


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
