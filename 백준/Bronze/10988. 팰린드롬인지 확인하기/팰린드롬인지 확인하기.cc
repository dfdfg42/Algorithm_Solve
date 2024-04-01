#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <iomanip>
#include <tuple>
#include <sstream>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string input;
    cin >> input;

    bool flag = true;

    for (int i = 0; i < input.size() / 2; i++) {
        if (input[i] != input[input.size() - i-1]) {
            flag = false;
        }
    }

    if (flag) {
        cout << 1 << '\n';
    }
    else {
        cout << 0 << '\n';
    }

    return 0;
}
