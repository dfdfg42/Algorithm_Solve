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
#include <string>
#include <sstream>
using namespace std;
typedef long long ll;

void solve() {
    
    int n;
    cin >> n;
    
    int ans = 2;
    int d = 2;
    for (int i = 2; i <= n; i++) {
        ans += d;
        if(i%3 != 0)
        d++;
    }

    cout << ans << '\n';

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}