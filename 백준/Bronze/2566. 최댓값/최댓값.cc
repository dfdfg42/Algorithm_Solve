#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <iomanip>
#include <tuple>
#include <sstream>
#include <map>
#include <algorithm>
#include <climits>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int maxInt = INT_MIN;
    int r, c;
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            int input; cin >> input;

            if (maxInt < input) {
                maxInt = input;
                r = i;
                c = j;
            }
        }
    }

    cout << maxInt << '\n' << r << ' ' << c << '\n';
        
    return 0;
}
