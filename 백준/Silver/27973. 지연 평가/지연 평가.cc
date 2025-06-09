#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;


typedef long long ll;
ll q;
ll point;

ll wm;

void solve() {
    
    point = 1;
    wm = 1;

    cin >> q;
    while (q--) {
        ll a;
        ll x;
        cin >> a;
        if (a == 3) {
            cout << point << '\n';
            continue;
        }
        else {
            cin >> x;
        }
        
        if (a == 0) {
            point += x;
        }
        else if (a == 1) {
            point *= x;
            wm *= x;

        }
        else if (a == 2) {
            if (wm > 0) {
                point += (wm * x);
            }
            else {
                point += x;
            }
        }

    }

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}

