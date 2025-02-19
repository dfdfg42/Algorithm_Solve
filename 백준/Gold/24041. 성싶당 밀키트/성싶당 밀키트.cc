#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int n, k;
ll g;
vector<int> s_arr, l_arr, o_arr;

bool possible(int x) {
    ll total = 0;
    vector<ll> removable; // o_arr[i] == 1인 경우에 해당하는 재료들의 세균수를 저장

    for (int i = 0; i < n; i++) {
        // x일째의 세균수: s * max(1, x - l)
        ll bacteria = (ll)s_arr[i] * max(1, x - l_arr[i]);
        total += bacteria;
        if (o_arr[i] == 1) {
            removable.push_back(bacteria);
        }
    }

    // 내림차순 정렬하여 가장 큰 세균수부터 제거
    sort(removable.begin(), removable.end(), greater<ll>());
    for (int i = 0; i < min(k, (int)removable.size()); i++) {
        total -= removable[i];
    }

    return total <= g;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> g >> k;
    s_arr.resize(n);
    l_arr.resize(n);
    o_arr.resize(n);

    int maxL = 0;
    for (int i = 0; i < n; i++) {
        cin >> s_arr[i] >> l_arr[i] >> o_arr[i];
        maxL = max(maxL, l_arr[i]);
    }

    // 최대 날짜 upper bound를 maxL + g로 설정
    ll left = 1, right = maxL + g, ans = 0;
    while (left <= right) {
        ll mid = (left + right) / 2;
        if (possible(mid)) {
            ans = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    cout << ans << "\n";
    return 0;
}
