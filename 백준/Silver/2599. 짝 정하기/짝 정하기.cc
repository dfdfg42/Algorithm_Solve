#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int am, af, bm, bf, cm, cf;
    cin >> am >> af;
    cin >> bm >> bf;
    cin >> cm >> cf;

    bool possible = false;

    for (int ab = 0; ab <= min(am, bf); ++ab) {

        int ac = am - ab;

        if (ac > cf) continue;

        int cb = bf - ab;

        if (cb > cm) continue;

        int bc = cf - ac;

        int ca = cm - cb;

        int ba = bm - bc;

        if (ba >= 0 && (ba + ca == af)) {
            cout << 1 << "\n";
            cout << ab << " " << ac << "\n";
            cout << ba << " " << bc << "\n";
            cout << ca << " " << cb << "\n";
            possible = true;
            break;
        }
    }

    if (!possible) {
        cout << 0 << "\n";
    }

    return 0;
}