#include <iostream>
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int w, h;
    int p, q;
    int t;

    cin >> w >> h;
    cin >> p >> q;
    cin >> t;


    int x = (p + t) % (2 * w); 
    
    if (x > w) {
        x = 2 * w - x;
    }

    int y = (q + t) % (2 * h);
    if (y > h) {
        y = 2 * h - y;
    }

    cout << x << " " << y << "\n";

    return 0;
}