#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.length();
    int aCount = count(s.begin(), s.end(), 'a');

    if (aCount == 0 || aCount == n) {
        cout << 0 << '\n';
        return 0;
    }

    s += s;

    int minSwaps = INT_MAX;
    int bCount = 0;

    for (int i = 0; i < aCount; ++i) {
        if (s[i] == 'b') {
            bCount++;
        }
    }
    minSwaps = bCount;

    for (int i = 1; i < n; ++i) {
        if (s[i - 1] == 'b') {
            bCount--;
        }
        if (s[i + aCount - 1] == 'b') {
            bCount++;
        }
        minSwaps = min(minSwaps, bCount);
    }

    cout << minSwaps << '\n';
    return 0;
}
