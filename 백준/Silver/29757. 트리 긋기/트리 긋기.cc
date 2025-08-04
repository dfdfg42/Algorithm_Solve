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

    vector<pair<pair<int, int>, int>> points;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points.push_back({{x,y},i + 1 });
    }

    sort(points.begin(), points.end());

    for (int i = 1; i < n; i++) {
        cout <<  points[i-1].second <<' ' << 
        points[i].second <<'\n';
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}