#include <iostream>
#include <vector>
#include <cmath> 
#include <queue>
using namespace std;


int n;
int s;
int ans;
vector<int> way;
vector<bool>visited;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    way.resize(n+1);
    visited.resize(n + 1, false);
    for (int i = 1; i <= n; i++) {
        cin >> way[i];
    }
    cin >> s;
    ans = 1;

    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int now = q.front();
        //cout << now << '\n';
        q.pop();

        int nl = now - way[now];
        int nr = now + way[now];
        if (nl >= 1 && !visited[nl]) {
            q.push(nl);
            visited[nl] = true;
            ans++;
        }
        if (nr <= n && !visited[nr]) {
            q.push(nr);
            visited[nr] = true;
            ans++;
        }

    }

    cout << ans << '\n';

    return 0;
}