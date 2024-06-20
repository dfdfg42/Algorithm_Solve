#include <iostream>
#include <vector>
#include <string>

using namespace std;



int main() {
    
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        int count = 0;
        if (a >= 10) {
            count++;
        }
        if (b >= 10) {
            count++;
        }
        if (c >= 10) {
            count++;
        }

        cout << a << ' ' << b << ' ' << c << '\n';
        if (count == 0) {
            cout << "zilch" << '\n';
        }
        else if (count == 1) {
            cout << "double" << '\n';
        }
        else if (count == 2) {
            cout << "double-double" << '\n';
        }
        else if (count == 3) {
            cout << "triple-double" << '\n';
        }
        cout << '\n';
    }

    return 0;
}
