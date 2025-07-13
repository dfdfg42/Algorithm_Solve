#include <iostream>
#include <vector>

using namespace std;



void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a + b + c + d <= 1500) {
        cout << "Yes" << '\n';
    }
    else {
        cout << "No" << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    

    return 0;
}