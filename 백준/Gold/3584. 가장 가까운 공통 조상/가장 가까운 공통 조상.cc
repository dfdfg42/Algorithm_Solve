#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

typedef long long ll;

vector<int> parent;

void solve() {

    int n;
    cin >> n;
    parent.clear();
    parent.assign(n + 1,-1);

    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        parent[b] = a;
    }

    int a, b;
    cin >> a >> b;

    set<int> parents;
    int now = a;
    while (now != -1) {
        parents.insert(now);
        now = parent[now];
    }

    now = b;
    while (now != -1) {
        if (parents.find(now) != parents.end()) {
            cout << now << '\n';
            break;
        }
        else
        now = parent[now];

    }
    

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    solve();

    return 0;
}
