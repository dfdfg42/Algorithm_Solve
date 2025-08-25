#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <set>
#include <cmath>
using namespace std;

typedef unsigned long long ll;
typedef long double ld;




int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll X, K;
    cin >>  X>> K;

    ll cnt = 0;
    ll Y = 0;
    for (int i = 0; i < 65; i++) {
        if ((X >> i) & 1LL) continue;
        if ((K >> cnt) & 1LL) {
            Y |= (1LL << i);
        }
        cnt++;
    }


    cout << Y << '\n';

    return 0;
}