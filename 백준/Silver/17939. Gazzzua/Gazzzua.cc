#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int income;
vector<int> chart;
int haveCoins;
vector<int> nowMax;

void solve() {
    income = 0;
    cin >> n;
    chart.resize(n);
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

    solve();

    return 0;
}