#include <iostream>
#include <vector>
#include <iomanip> 
#include <queue>
#include <algorithm>

using namespace std;

typedef long double ld;
typedef long long ll;

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}



int n;
ll x1, x2, x3, x5, x6, x7;
ll c1, c2, c3, c4, c5, c6;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin >> c1 >> c2 >> c3 >> c4 >> c5 >> c6;

    x2 = gcd(c1, c5);
	x1 = c1 / x2;
	x3 = c5 / x2;

	x6 = gcd(c3, c6);
	x7 = c3 / x6;
    x5 = c6 / x6;
    
    cout << x1 << ' ' << x2 << ' ' << x3<<' ' << x5<< ' ' << x6<<' ' << x7 << '\n';
    
    
    return 0;
}