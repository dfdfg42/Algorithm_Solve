#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <queue>
#include <unordered_map>
#include <tuple>
#include <algorithm>
#include <map>


using namespace std;

typedef long long ll;

int n;


void solve() {

    int n;
    cin >> n;

    vector<int> alps;
    ll ans = 0;

    int temp;
    cin >> temp;
    ans += temp * temp *2 ;
    for (int i = 1; i < n-1; i++) {
        int input;
        cin >> input;
        ans += (input * input) *4;
    }
    int temp2;
    cin >> temp2;
    ans += temp2 * temp2 * 2;
    cout << ans << '\n';

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    

    return 0;
}