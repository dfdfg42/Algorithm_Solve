#include <iostream>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin.tie(0);
    ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
    if (n == 1) cout << 0;
    else if (n & (1 << 0)) cout << (n / 2) + 1;
    else cout << n / 2;
}
