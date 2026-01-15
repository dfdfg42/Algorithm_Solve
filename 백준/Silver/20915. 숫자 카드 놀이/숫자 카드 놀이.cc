#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;

void solve(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '6') s[i] = '9';
    }

    sort(s.begin(), s.end(), greater<char>());

    ll a = 0;
    ll b = 0;


    for (int i = 0; i < s.length(); i++) {
        int num = s[i] - '0';

        if (a <= b) {
            a = a * 10 + num;
        }
        else {
            b = b * 10 + num;
        }
    }

    cout << a * b << '\n';
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;
        solve(s);
    }

    return 0;
}