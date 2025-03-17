#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

typedef long long ll;
vector<tuple<int, int, int>> crimes;  // 각 사건: (t, x, y)

int binarySearchLowerBound(int ct) {
    int lo = 0, hi = crimes.size();
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        int t = get<0>(crimes[mid]);
        if (t >= ct) {
            hi = mid;
        }
        else {
            lo = mid + 1;
        }
    }
    return lo;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int g, n;
    cin >> g >> n;

    crimes.resize(g);
    for (int i = 0; i < g; i++) {
        int x, y, t;
        cin >> x >> y >> t;
        crimes[i] = make_tuple(t, x, y);
    }
    // 시간 기준 오름차순 정렬
    sort(crimes.begin(), crimes.end());

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int cx, cy, ct;
        cin >> cx >> cy >> ct;
        bool unreachable = false;

      
        int pos = binarySearchLowerBound(ct);

        // 알리바이 시간 이후의 사건 검사
        if (pos < g) {
            int t, x, y;
            tie(t, x, y) = crimes[pos];
            ll dt = (ll)t - ct;  // 시간 차
            ll distSq = (ll)(cx - x) * (cx - x) + (ll)(cy - y) * (cy - y);
            if (distSq > dt * dt) {
                unreachable = true;
            }
        }


        if (pos - 1 >= 0) {
            int t, x, y;
            tie(t, x, y) = crimes[pos - 1];
            ll dt = (ll)ct - t;
            ll distSq = (ll)(cx - x) * (cx - x) + (ll)(cy - y) * (cy - y);
            if (distSq > dt * dt) {
                unreachable = true;
            }
        }

        if (unreachable)
            ans++;
    }

    cout << ans << "\n";
    return 0;
}
