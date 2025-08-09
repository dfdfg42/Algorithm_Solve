#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

vector<int> parent;
int n;
int tc;

int Find(int a) {
    if (parent[a] == a) return a;
    return parent[a] = Find(parent[a]);
}

void Union(int a, int b) {
    a = Find(a); b = Find(b);
    if (a != b) parent[b] = a;
}

void Init() {
    parent.resize(n);           
    for (int i = 0; i < n; i++) parent[i] = i;
}

void solve() {
    Init();

    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        Union(a, b);
    }

    int m;
    cin >> m;

    cout << "Scenario " << tc << ":" << '\n';
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cout << (Find(a) == Find(b) ? 1 : 0) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (tc = 1; tc <= T; ++tc) {
        cin >> n;        
        solve();
        if (tc < T) cout << '\n';   
    }
    return 0;
}
