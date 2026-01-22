#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

string s;

bool is_akaraka( int len) {

    if (len == 1) return true;

    for (int i = 0; i < len/2; i++) {
        if (s[i] != s[len - 1 - i]) {
            return false;
        }
    }

    return is_akaraka(len / 2);

}


int main() {

    ios::sync_with_stdio(0); cin.tie(0);



    cin >> s;


    if (is_akaraka(s.length())) {
        cout << "AKARAKA" << '\n';
    }
    else {
        cout << "IPSELENTI" << '\n';
    }



    return 0;
}