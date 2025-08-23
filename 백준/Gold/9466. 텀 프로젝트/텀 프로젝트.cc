#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <cstring>

using namespace std;
vector<int> s;
vector<bool> visited,finished;
int cnt;

void dfs(int cur) {
    visited[cur] = true;
    int nxt = s[cur];

    if (!visited[nxt]) {
        dfs(nxt);
    }
    else if (!finished[nxt]) {

        for (int i = nxt; i != cur; i = s[i]) {
            cnt++;
        }
        cnt++; 
    }

    finished[cur] = true;
}

void solve() {
    int n;
    cin >> n;
    cnt = 0;
    s.assign(n + 1, 0);
    visited.assign(n + 1, false);
    finished.assign(n + 1, false);
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) dfs(i);
    }

    
    cout << n - cnt << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    

    return 0;
}