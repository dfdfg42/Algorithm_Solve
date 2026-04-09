#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <regex>

using namespace std;

typedef long long ll;

bool match(string s) {

    regex pattern("(100+1+|01)+");
    smatch m;
    if (regex_match(s, m, pattern)) {
        return true;
    }
    else {
        return false;
    }

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    string s;
    cin >> s;

    if (match(s)) {
        cout << "SUBMARINE\n";
    }
    else {
        cout << "NOISE\n";
    }



    return 0;
}