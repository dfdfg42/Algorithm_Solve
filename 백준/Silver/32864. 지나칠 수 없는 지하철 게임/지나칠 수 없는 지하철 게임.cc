#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    vector<int> lines(n);
    
    for (int i = 0; i < n; i++) {
        cin >> lines[i];
    }

    int whoWin = 0; //0 세훈 1 민아
    for (int i = n - 2; i >= 0; i--) {
        if (lines[i] == 0) {

        }
        else if(lines[i]== 1) {

            if (i == 1) {
                if (whoWin == 1) whoWin = 0;
                else whoWin = 1;
                i--;
            }
            else if (lines[i - 1] == 0) {
                if (whoWin == 1) whoWin = 1;
                else whoWin = 0;
                i--;
            }
            else if (lines[i - 1] == 1) {
                if (whoWin == 1) whoWin = 1;
                else whoWin = 0;
                i--;
            }
        }
    }

    if (whoWin==0) {
        cout << "mnx" << '\n';
    }
    else {
        cout << "alsdkffhgk" << '\n';
    }

    return 0;
}
