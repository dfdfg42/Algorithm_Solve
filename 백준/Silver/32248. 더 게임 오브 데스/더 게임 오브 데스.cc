#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <cstring>

using namespace std;

typedef long long ll;
typedef long double ld;

ll n, t;
vector<int> a;
vector<bool> visited;

//사이클 크기만 검출
int dfs(int now , int start ,int cnt) {

    if (now == start) {
        return cnt;
    }
    else {
        cnt++;
        return dfs(a[now], start, cnt);
    }

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    cin >> n >> t;
    a.assign(n + 1,0);
    visited.assign(n + 1, false);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int now = 1;
    bool cycled = false;
    while (t > 0) {
        visited[now] = true;
        now = a[now];
        t--;
        if (visited[now] && !cycled) {
            int cycleCount = dfs(a[now], now, 1);

            t %= cycleCount;
            cycled = true;
        }

    }

    cout << now << '\n';

    return 0;
}