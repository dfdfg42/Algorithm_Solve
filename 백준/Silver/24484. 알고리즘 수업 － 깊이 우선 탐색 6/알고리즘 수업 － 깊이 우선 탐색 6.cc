#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int n, m, r;

vector<vector<int>> graph;
vector<ll> depths;
vector<ll> visitNums;
int visitNum;

void dfs(int now ,int depth ) {


    for (auto a : graph[now]) {

        if (visitNums[a] == 0) {
            visitNums[a] = ++visitNum;
            depths[a] = depth + 1;
            dfs(a, depth + 1);
        }
    }


}

int main() {

    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> r;

    graph.resize(n+1);
    depths.resize(n+1,-1);
    visitNums.resize(n+1,0);

    depths[r] = 0;
    visitNums[r] = 1;
    visitNum = 1;

    for (int i = 0; i < m; i++) {

        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);

    }
    
    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end(), greater<int>());
        
    }

    dfs(r,0);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        //cout << i << ' ' << visitNums[i]  << " " << depths[i] << '\n';
        if (visitNums[i] > 0) {
            ans += depths[i] * visitNums[i];
        }
    }

    cout << ans << '\n';

    return 0;
}