#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;


typedef long long ll;
int n, m;
ll ans = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    vector<pair<int, int>> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i].first >> t[i].second;
    }
    sort(t.begin(), t.end());

    bool flag = false;

    for (int i = 0; i < n-1; i++) {
        int start = t[i].first;
        int end = t[i].second;
        if (end > t[i + 1].first && t[i + 1].second > end) {
            t[i + 1].first = end;
        }
        else if (end > t[i + 1].first && t[i + 1].second <= end) {
            t[i + 1].first = start;
            t[i + 1].second = end;
            start = end;
        }
        ans += abs(end - start);


    }
    ans += abs(t[n-1].second - t[n-1].first);


    cout << ans << '\n';



    return 0;
}