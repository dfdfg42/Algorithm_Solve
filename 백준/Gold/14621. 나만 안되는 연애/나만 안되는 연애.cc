#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

typedef long long ll;

int n, m;
vector<int> parent;
vector<char> gender;

int Find(int a) {
    if (parent[a] == a) return a;
    return parent[a] = Find(parent[a]);
}

void Union(int a, int b) {
    a = Find(a); b = Find(b);
    if (a != b) parent[b] = a;
}

void solve() {


    cin >> n >> m;
    parent.resize(n+1);
    gender.resize(n + 1);
    for (int i = 0; i <= n; i++) parent[i] = i;
    for (int i = 1; i <= n; i++) cin >> gender[i];

    //비용 , u v
    priority_queue < pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>
    , greater<pair<int, pair<int, int>>>> pq;
    for (int i = 0; i < m; i++) {
        int d, u, v;
        cin >> u>> v >> d;
        pq.push({ d,{u,v} });
    }

    int mstCost = 0;
    int used = 0;
    while (!pq.empty() && used < n - 1) {
        int d = pq.top().first;
        int u = pq.top().second.first;
        int v = pq.top().second.second;
        pq.pop();

        if (Find(u) != Find(v) && gender[u] != gender[v]) {
            Union(u, v);
            mstCost += d;
            used++;
        }
    }

    if (used == n - 1) cout << mstCost << '\n';
    else cout << -1 << '\n';

    

    
    

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
