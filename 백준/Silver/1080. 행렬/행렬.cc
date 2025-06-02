#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef long double ld;

int n, m;
vector<vector<int>> oriBoard;
vector<vector<int>> board;

void boardRev(int y, int x) {

    for (int i = y; i < y + 3; i++) {
        for (int j = x; j < x + 3; j++) {
            if (board[i][j] == 1) {
                board[i][j] = 0;
            }
            else {
                board[i][j] = 1;
            }
        }
    }

}

bool boardCmp(int y, int x) {

    if (oriBoard[y][x] != board[y][x]) {
        return false;
    }
    

    return true;
}

bool boardCheck() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (oriBoard[i][j] != board[i][j]) {
                return false;
            }
        }
    }

    return true;
}


void viewBoard() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }
    cout << "============\n";
}

void solve() {

    cin >> n >> m;
    int ans = 0;

    oriBoard.resize(n, vector<int>(m));
    board.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < m; j++) {
            board[i][j] = s[j] - '0';
        }
    }

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < m; j++) {
            oriBoard[i][j] = s[j] -'0';
        }
    }

    //viewBoard();

    //n-2, m-2 까지 3칸씩 보면서 다르다면 뒤집기

    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < m - 2; j++) {
            
            if (!boardCmp(i, j)) {
                boardRev(i, j);
                //viewBoard();
                ans++;
            }

        }
    }

    //cout << "============\n";
    //viewBoard();
    if (boardCheck()) {
        cout << ans << '\n';
    }
    else {
        cout << -1 << '\n';
    }


    

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    solve();



    return 0;
}