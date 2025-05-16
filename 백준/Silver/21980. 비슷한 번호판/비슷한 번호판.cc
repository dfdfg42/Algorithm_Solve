#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        map <pair<vector<int>, int>, int> m;

        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;

            vector<int> c(26, 0);
            int up = 0;
            for (int j = 0; j < s.length(); j++) {
                c[tolower(s[j]) - 'a'] += 1;
                if (isupper(s[j])) up += 1;
            }

            m[{c, up}]++;
        }

        int ans = 0;
        for (auto a : m) {
            if (a.second > 1) {
                ans += (long long)a.second * (a.second - 1) / 2;
            }
        }
        cout << ans << '\n';

    }
    return 0;
}
