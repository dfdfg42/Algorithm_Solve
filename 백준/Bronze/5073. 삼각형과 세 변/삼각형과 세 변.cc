#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        vector<int> s(3);
        cin >> s[0] >> s[1] >> s[2];

        if (s[0] == 0 && s[1] == 0 && s[2] == 0) break;

        sort(s.begin(), s.end());

        if (s[2] >= s[0] + s[1]) {
            cout << "Invalid" << "\n";
        } else if (s[0] == s[1] && s[1] == s[2]) {
            cout << "Equilateral" << "\n";
        } else if (s[0] == s[1] || s[1] == s[2] || s[0] == s[2]) {
            cout << "Isosceles" << "\n";
        } else {
            cout << "Scalene" << "\n";
        }
    }

    return 0;
}