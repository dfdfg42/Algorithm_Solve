#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int G;
    cin >> G;

    bool found = false;

    for (int x = 1; x <= 100000; x++) {

        long long y2 = (long long)x * x - G;

        int y = (int)sqrt(y2);
        if (y > 0 && (long long)y * y == y2) {
            cout << x << '\n';
            found = true;
        }
    }

    if (!found) {
        cout << -1 << '\n';
    }

    return 0;
}
