#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;


int main() {

    ios::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    vector<int> card(n + 1);
    vector<int> d(n + 1,123456789);
    for (int i = 1; i <= n; i++) {
        cin >> card[i];
    }
    d[0] = 0;
    d[1] = card[1];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <=i; j++) {
            d[i] = min(d[i], d[i - j] + card[j]);
        }
    }

    cout << d[n];

    return 0;
}