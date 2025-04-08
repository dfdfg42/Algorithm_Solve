#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> X(n), T(n);

    for (int i = 0; i < n; i++) {
        cin >> X[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> T[i];
    }

    int time = X[n - 1];

    for (int i = n - 1; i >= 0; i--) {
        if (i < n - 1) {

            time += X[i + 1] - X[i];
        }

        if (time < T[i]) {
            time = T[i];
        }
    }


    time += X[0];

    cout << time << "\n";
    return 0;
}
