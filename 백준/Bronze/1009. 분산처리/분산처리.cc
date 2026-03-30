#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int a, b;
        cin >> a >> b;

        int base = a % 10;
        
        if (base == 0) {
            cout << 10 << "\n";
            continue;
        }

        int res = 1;
        int exp = (b % 4 == 0) ? 4 : b % 4;

        for (int i = 0; i < exp; i++) {
            res = (res * base) % 10;
        }

        cout << res << "\n";
    }

    return 0;
}