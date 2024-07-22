#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;





int main() {
    string s,t;
    cin >> s >> t;



    while (true) {

        if (t[t.length() - 1] == 'A') {
            t.pop_back();
        }
        else {
            t.pop_back();
            reverse(t.begin(), t.end());
        }

        if (t.length() == s.length()) {
            if (s == t) {
                cout << 1 << '\n';
            }
            else {
                cout << 0 << '\n';
            }
            break;
        }
    }


    return 0;
}
