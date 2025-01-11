#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n;
int isUse;
vector<vector<int>> board;

bool checkRow() {

    bool check = false;

    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (board[i][j] == isUse) count++;
        }

        if (count > n / 2 && count != n) {
            for (int j = 0; j < n; j++) {
                board[i][j] = isUse;
            }
            check = true;
        }
    }

    return check;

}

bool checkCol() {

    bool check = false;

    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (board[j][i] == isUse) count++;
        }

        if (count > n / 2 && count !=n) {
            for (int j = 0; j < n; j++) {
                board[j][i] = isUse;
            }
            check = true;
        }
    }

    return check;
}

bool isConfirm() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] != isUse) return false;
        }
    }

    return true;
}

bool isPossible() {

    while (true) {

        if (!checkRow() && !checkCol()) {
            if (isConfirm()) {
                return true;
            }else    return false;
        
        }

  
    }


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    cin >> isUse;

    board.resize(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    

    if (isPossible()) {
        cout << 1 << endl;
    }
    else cout << 0 << endl;


    return 0;
}
