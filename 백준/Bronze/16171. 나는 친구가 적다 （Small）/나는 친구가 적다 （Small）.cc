#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    string find;
    cin >> find;

    string convert = "";
    for (int i = 0; i < s.length(); i++) {
        if (!isdigit(s[i])) {
            convert += s[i];
        }
    }

    //cout << convert << '\n';

    bool flag = false;
    for (int i = 0; i <= convert.length() - find.length(); i++) {
        if (convert.substr(i, find.length()) == find) {
            
            flag = true;
            break;
        }
    }
    if (convert.length() < find.length()) flag = false;
    

    if (flag) cout << "1" << '\n';
    else cout << "0" << '\n';




    return 0;
}
