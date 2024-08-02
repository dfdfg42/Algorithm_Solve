#include <iostream>
#include <string>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    ll a, b;
    cin >> a >> b;

    ll result_gcd = gcd(a, b);

    string result(result_gcd, '1');

    cout << result << '\n';

    return 0;
}
