#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;

char convert(char c) {
    if (c == 'R') return 'G';
    if (c == 'G') return 'B';
    return 'R';
}

bool solve(vector<char> s, int &ans) {
    for (int i = 0; i <= n - 3; i++) {
        while (s[i] != s[0]) { 
            s[i] = convert(s[i]);
            s[i + 1] = convert(s[i + 1]);
            s[i + 2] = convert(s[i + 2]);
            ans++;
        }
    }

    for (int i = 1; i < n; ++i) {
        if (s[i] != s[0]) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    string str;
    cin >> str;
    vector<char> s(n);
    for (int i = 0; i < n; i++) s[i] = str[i];
    int min_ops = -1;


    for (int initial = 0; initial < 3; ++initial) {
        vector<char> temp_s = s;
        int ops = 0;

        if (initial > 0) {
            for (int k = 0; k < initial; ++k) { 
                temp_s[0] = convert(temp_s[0]);
                temp_s[1] = convert(temp_s[1]);
                temp_s[2] = convert(temp_s[2]);
                ops++;
            }
        }


        if (solve(temp_s, ops)) {

            if (min_ops == -1 || ops < min_ops) {
                min_ops = ops;
            }
        }
    }
    cout << min_ops;
}
