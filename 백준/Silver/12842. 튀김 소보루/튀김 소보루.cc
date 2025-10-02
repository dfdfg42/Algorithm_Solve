#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, s, m;
    cin >> n >> s;
    cin >> m;

    vector<int> times(m);
    for (int i = 0; i < m; i++) {
        cin >> times[i];
    }

    int eaten_target = n - s;

    int spent = 0;
    int lastNum = -1;

    for (int i = 0; i < m; i++) {
        spent++;
        lastNum = i + 1;
        if (spent == eaten_target) {
            cout << lastNum << '\n';
            return 0;
        }
    }

    long long time = 1;
    while (true) {

        for (int i = 0; i < m; i++) {

            if (time % times[i] == 0) {
                spent++;
                lastNum = i + 1;
                if (spent == eaten_target) {
                    cout << lastNum << '\n';
                    return 0; 
                }
            }
        }
        time++;
    }

    return 0;
}