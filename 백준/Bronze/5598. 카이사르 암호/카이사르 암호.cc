#include <iostream>
#include <string>
using namespace std;

int main() {
    string cipher;
    cin >> cipher;  

    for (char c : cipher) {
    
        if (c == 'A') {
            cout << 'X';
        } else if (c == 'B') {
            cout << 'Y';
        } else if (c == 'C') {
            cout << 'Z';
        } else {
            cout << char(c - 3);
        }
    }

    cout << "\n";
    return 0;
}