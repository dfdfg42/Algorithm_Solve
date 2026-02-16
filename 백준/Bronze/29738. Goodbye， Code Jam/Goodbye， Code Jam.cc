#include <iostream>
#include <string>

using namespace std;

void solve(int caseNum) {
    int N;
    cin >> N;

    string lastRound;

    if (N > 4500) {
        lastRound = "Round 1";
    } else if (N > 1000) {
        lastRound = "Round 2";
    } else if (N > 25) {
        lastRound = "Round 3";
    } else {
        lastRound = "World Finals";
    }

    cout << "Case #" << caseNum << ": " << lastRound << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int i = 1; i <= T; ++i) {
        solve(i);
    }

    return 0;
}