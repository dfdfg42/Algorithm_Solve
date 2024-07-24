#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <climits>
using namespace std;

int main() {
    
    string s;
    cin >> s;

    int n = s.length();
    int aCount = 0;
    int bCount = 0;
    int minBCount = INT_MAX;
    for (char c : s) {
        if (c == 'a') {
            aCount++;
        }
    }
    
    s += s;

    for (int i = 0; i < n; i++) {
        int j =i + aCount-1;

        for (int k = i; k <= j; k++) {
            if (s[k] == 'b') {
                bCount++;
            }
        }
        minBCount = min(bCount, minBCount);
        bCount = 0;
    }

    cout << minBCount << '\n';


}
