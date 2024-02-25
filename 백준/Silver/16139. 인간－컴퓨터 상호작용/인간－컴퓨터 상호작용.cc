#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;

    vector<vector<int>> alphaCount(s.size(), vector<int>(26, 0));

    alphaCount[0][s[0] - 'a'] = 1;

    for (int i = 1; i < s.size(); i++) {
        for (int j = 0; j < 26; j++) {
            alphaCount[i][j] = alphaCount[i - 1][j];
        }
        alphaCount[i][s[i] - 'a'] += 1;
    }

    int q;
    cin >> q;
    while (q--) {
        char alpha;
        int l, r;
        cin >> alpha >> l >> r;

        int count = alphaCount[r][alpha - 'a'];
        if (l > 0) {
            count -= alphaCount[l - 1][alpha - 'a'];
        }

        cout << count << '\n';
    }

    return 0;
}
