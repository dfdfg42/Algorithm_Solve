#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;  cin >> N;
    vector<ll> y(N);
    for (auto& v : y) cin >> v;

    set<pair<ll,ll>> S;      // 모든 오염 칸 (x,y)
    ll curX = 0;
    for (int i = 0; i < N; ++i) {
        if (i && y[i] <= y[i-1]) ++curX;   // 이전보다 작거나 같으면 새 열
        S.emplace(curX, y[i]);
    }

    int minCnt = 0;
    queue<pair<ll,ll>> q;

    while (!S.empty()) {
        ++minCnt;
        auto start = *S.begin();   // 아직 처리 안 한 칸 하나 잡기
        S.erase(S.begin());
        q.push(start);

        while (!q.empty()) {
            auto [x, yy] = q.front(); q.pop();
            for (int d = 0; d < 4; ++d) {
                pair<ll,ll> nxt = {x + dx[d], yy + dy[d]};
                auto it = S.find(nxt);
                if (it != S.end()) {
                    q.push(nxt);
                    S.erase(it);   // 방문 표시 겸 set에서 제거
                }
            }
        }
    }

    cout << minCnt << '\n' << N << '\n';
    return 0;
}
