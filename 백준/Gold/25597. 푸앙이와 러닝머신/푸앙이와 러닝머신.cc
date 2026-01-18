#include <iostream>

using namespace std;
using ll = long long;

ll X, T;

bool solve(ll t8, ll t4, ll t1) {
    if (t8 + t4 + t1 > T) return false;

    int cnt = 0;
    if (t8 > 0) cnt++;
    if (t4 > 0) cnt++;
    if (t1 > 0) cnt++;

    cout << cnt << "\n";


    ll current_time = T - (t8 + t4 + t1);

    if (t8 > 0) {
        cout << current_time << " 8\n";
        current_time += t8;
    }
    if (t4 > 0) {
        cout << current_time << " 4\n";
        current_time += t4;
    }
    if (t1 > 0) {
        cout << current_time << " 1\n";
        current_time += t1;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> X >> T;

    if (X > T * 8) {
        cout << -1;
        return 0;
    }


    if (X % 8 == 0 && solve(X/8, 0, 0)) return 0;
    if (X % 4 == 0 && solve(0, X/4, 0)) return 0; 
    if (solve(0, 0, X)) return 0;                 


    if (X % 8 == 4 && solve(X/8, 1, 0)) return 0;
    if (solve(X/8, 0, X%8)) return 0;
    if (solve(0, X/4, X%4)) return 0;


    ll a = X / 8;
    ll rem = X % 8;
    ll b = rem / 4;
    ll c = rem % 4;
    if (solve(a, b, c)) return 0;

    cout << -1;
    return 0;
}