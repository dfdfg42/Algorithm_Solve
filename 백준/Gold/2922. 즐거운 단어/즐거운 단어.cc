#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

string s;
int n;

bool isVowel(char c) {
    return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}


ll solve(int idx, int v_cnt, int c_cnt, bool hasL) {
    if (v_cnt >= 3 || c_cnt >= 3) return 0;

    if (idx == n) {
        return hasL ? 1 : 0; 
    }

    ll res = 0;

    if (s[idx] != '_') {
        if (isVowel(s[idx])) {
            res = solve(idx + 1, v_cnt + 1, 0, hasL);
        }
        else {
            res = solve(idx + 1, 0, c_cnt + 1, hasL || (s[idx] == 'L'));
        }
    }
    else {
        res += 5 * solve(idx + 1, v_cnt + 1, 0, hasL);

        res += 20 * solve(idx + 1, 0, c_cnt + 1, hasL);

        res += 1 * solve(idx + 1, 0, c_cnt + 1, true);
    }

    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    n = s.length();

    cout << solve(0, 0, 0, false) << endl;

    return 0;
}