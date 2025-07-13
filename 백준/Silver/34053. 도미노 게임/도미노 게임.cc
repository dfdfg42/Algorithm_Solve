#include <iostream>
#include <vector>
#include <climits>

using namespace std;

typedef long long ll;

ll minSec;
ll sumSec;

void solve() {
    minSec = LLONG_MAX;
    sumSec = 0;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        ll temp;
        cin >> temp;

        minSec = min(temp, minSec);
        sumSec += temp;

    }

    cout << sumSec - minSec << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    

    return 0;
}