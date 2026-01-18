#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, m;
    cin >> n >> m;

    if (n != m) {
        cout << 0 << '\n';

    }
    else {
        cout << 1 << '\n';
    }

    return 0;
}