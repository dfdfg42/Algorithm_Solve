#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <queue>
#include <unordered_map>
#include <tuple>
#include <algorithm>
#include <map>
#include <deque>


using namespace std;

typedef long long ll;

int n, m;
vector<pair<int, int>> subjs; // 값,순서
deque<pair<ll, int>> ans;

void solve() {
    cin >> n >> m;
    subjs.reserve(m + 1);
    for (int i = 1; i <= m; i++) {
        int input;
        cin >> input;
        subjs.push_back({ input,i });
    }

    sort(subjs.begin(), subjs.end());

    ll sum = 0;
    for (int i = 0; i < m; ++i) {

        if (sum < n) {
            ans.push_back({ subjs[i].first, subjs[i].second });
            sum += subjs[i].first;
        }
        while (!ans.empty() && sum > 2 * n) {
            sum -= ans.front().first;
            ans.pop_front();

        }

        if (sum >= n && sum <= 2 * n) {
            break;
        }
    }

    cout << ans.size() << '\n';
    for (auto a : ans) {
        cout << a.second << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();



    return 0;
}