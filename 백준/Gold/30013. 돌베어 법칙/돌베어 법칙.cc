#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;

    int ans = 1e9;
    for (int p = 1; p <= n; p++) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '#' && (i - p < 0 || s[i - p] == '.')) {
                cnt++;
            }
        }
        ans = min(ans, cnt);
    }

    cout << (ans == 1e9 ? 0 : ans) << '\n';
}