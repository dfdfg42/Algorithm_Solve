#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <iomanip>
#include <tuple>
#include <sstream>
#include <map>
using namespace std;

string board;
int changeCount;
int maxVal;

void dfsFindMax(int idx, int changeCount)  {

    if (changeCount == 0) {
        maxVal = max(maxVal, stoi(board));
        return;
    }


    for (int i = idx; i < board.size(); i++) {
        for (int j = i + 1; j < board.size(); j++) {
            if (board[i] <= board[j]) {
                swap(board[i], board[j]);
                dfsFindMax(i, changeCount - 1);
                swap(board[i], board[j]);
            }

            if (i == board.size() - 2 && j == board.size() - 1) {
                swap(board[i], board[j]);
                dfsFindMax(i, changeCount - 1);
                swap(board[i], board[j]);
            }

        }
    }

}


int main() {   

    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> board >> changeCount;

        maxVal = 0;
        dfsFindMax(0, changeCount);

        cout << '#' << i +1<<" "<< maxVal << '\n';


    }

    return 0;  
}
