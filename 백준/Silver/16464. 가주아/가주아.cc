#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        long long N;
        cin >> N;
        bool canWin = false;
        while (N != 1) {
            if (N % 2 == 1) {
                canWin = true;
                break;
            }
            N /= 2;
        }
        if (canWin) {
            cout << "Gazua" << endl;
        } else {
            cout << "GoHanGang" << endl;
        }
    }
    return 0;
}
