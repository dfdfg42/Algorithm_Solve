#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct PairHash {
    size_t operator()(const pair<ll,ll>& p) const noexcept {
        return std::hash<ll>()(p.first ^ (p.second + 0x9e3779b97f4a7c15ULL
                                          + (p.first<<6) + (p.first>>2)));
    }
};

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<ll> y(N);
    for (auto& v : y) cin >> v;

    vector<pair<ll,ll>> pos(N);
    unordered_map<pair<ll,ll>, int, PairHash> mp;
    mp.reserve(N * 2);

    ll curX = 0;
    for (int i = 0; i < N; ++i) {
        if (i && y[i] <= y[i - 1]) ++curX;
        pos[i] = {curX, y[i]};
        mp[pos[i]] = i;
    }

    vector<char> vis(N, 0);
    int minCnt = 0;
    queue<int> q;

    for (int i = 0; i < N; ++i) if (!vis[i]) {
        ++minCnt;
        vis[i] = 1;
        q.push(i);
        while (!q.empty()) {
            int idx = q.front(); q.pop();
            auto [x, yy] = pos[idx];
            for (int d = 0; d < 4; ++d) {
                auto nxt = make_pair(x + dx[d], yy + dy[d]);
                auto it = mp.find(nxt);
                if (it != mp.end() && !vis[it->second]) {
                    vis[it->second] = 1;
                    q.push(it->second);
                }
            }
        }
    }

    cout << minCnt << '\n' << N << '\n';
    return 0;
}
