#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <string>

using namespace std;

typedef long long ll;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    long long sum = 0;
    int index = 0;
    for (int i = 0; i < s.length()-1; i++) {

        if (s[i] == '*') {
            index = i % 2;
            continue;
        }
            
        if (i % 2 != 0) {
            sum += (s[i] - '0')*3;
        }
        else {
            sum += s[i] - '0';
        }

    }

    int ans = 0;
    if (s[s.length()] - 1 == '*') {
        if (sum % 10 == 0) {
            cout << 0 << '\n';
        }else
        cout << 10 - (sum % 10) << '\n';
        return 0;
    }
    else {

        int m = s[s.length() - 1] - '0';
        for (int i = 0; i <= 9; i++) {
            
            int temp = sum;
            temp += index == 1 ? 3 * i : i;

            if (m == 0 && temp % 10 == 0) {
                cout << i << '\n';
            }
            else if (10 - (temp % 10) == m) {
                cout << i << '\n';
                return 0;
            }
        }

    }




    return 0;
}