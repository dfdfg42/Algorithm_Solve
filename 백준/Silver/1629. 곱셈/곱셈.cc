#include <iostream>

typedef long long ll;
using namespace std;

ll A, B, C;

ll calc(ll a, ll b) {
    if (b == 0) return 1;

    ll result = calc(a, b >> 1);
    result = (result * result) % C;

    if (b & 1) result = (result * a) % C;

    return result % C;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B >> C;
    cout << calc(A, B) % C;

    return 0;
}