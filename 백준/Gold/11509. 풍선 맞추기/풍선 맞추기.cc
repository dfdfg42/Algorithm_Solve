#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;

int n;
vector<int> arrows;
vector<int> seq;

int ans;
void solve() {
    cin >> n;
    ans = 0;
    arrows.resize(1'000'001,0);
    seq.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> seq[i];
    }

    for (auto a : seq) {
        if (arrows[a] == 0) {
            ans++;
            arrows[a - 1]++;
        }
        else if (arrows[a] >= 1) {
           
            arrows[a]--;
            arrows[a - 1]++;
        }
    }

    cout << ans << '\n';

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}