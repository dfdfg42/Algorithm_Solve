#include <iostream>
#include <regex>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    
    regex pattern("^(100+1+|01)+$"); // 정규 표현식 패턴

    while (t--) {
        string s;
        cin >> s;

        if (regex_match(s, pattern)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}
