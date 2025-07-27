#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

void solve() {

    int n;
    ll income;
    vector<ll> chart;
    ll haveCoins;
    vector<ll> nowMax;

    income = 0;
    haveCoins = 0;

    cin >> n;

    chart.clear();
    chart.resize(n);
    chart.clear();
    nowMax.resize(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> chart[i];
    }
    
    nowMax[n - 1] = chart[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        nowMax[i] = max(chart[i], nowMax[i + 1]);
    }

    for (int i = 0; i < n; i++) {
        if (chart[i] == nowMax[i]) {
            while (haveCoins > 0) {
                income += chart[i];
                haveCoins--;
            }
        }
        else {
            income -= chart[i];
            haveCoins++;
        }
    }

    cout << income << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
  

    return 0;
}