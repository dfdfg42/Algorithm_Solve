#include <iostream>
using namespace std;

int N;

void solve(int n, int k, int len) {
    int prev_len = (len - (k + 3)) / 2;

    if (n <= prev_len) {
        solve(n, k - 1, prev_len);
    }
    else if (n > prev_len + (k + 3)) {
        solve(n - (prev_len + k + 3), k - 1, prev_len);
    }
    else {

        if (n - prev_len == 1) cout << "m";
        else cout << "o";
        return;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    int len = 3;
    int k = 0;

    while (len < N) {
        k++;

        len = len * 2 + k + 3;
    }

    solve(N, k, len);

    return 0;
}