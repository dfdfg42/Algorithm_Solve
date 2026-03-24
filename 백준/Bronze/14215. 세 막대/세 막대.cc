#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    vector<int> s(3);
    for (int i = 0; i < 3; i++) {
        cin >> s[i];
    }

    sort(s.begin(), s.end());

    if (s[0] + s[1] > s[2]) {
        cout << s[0] + s[1] + s[2] << endl;
    } else {
        cout << (s[0] + s[1]) * 2 - 1 << endl;
    }

    return 0;
}