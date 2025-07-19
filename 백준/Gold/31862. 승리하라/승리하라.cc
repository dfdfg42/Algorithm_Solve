#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <queue>
#include <unordered_map>
#include <tuple>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;

vector<tuple<int, int, int>>  notMatch;
vector<int> score;
int n, m, k;
int ans;

void dfs(int idx ,int curMax , int curCnt) {

    if (idx == notMatch.size()) {
        if (score[k] == curMax && curCnt == 1)
            ans++;
        return;
    }

    int a = get<0>(notMatch[idx]);
    int b = get<1>(notMatch[idx]);
    int c = get<2>(notMatch[idx]);
    {
        int oldA = score[a];
        score[a]++;

        
        int nextMax = curMax, nextCnt = curCnt;
        if (score[a] > curMax) {
            nextMax = score[a];
            nextCnt = 1;
        }
        else {
            if (oldA == curMax) {
                nextCnt--;
            }
            if (score[a] == curMax) {
                nextCnt++;
            }
        }

        dfs(idx + 1, nextMax, nextCnt);
        score[a]--;  
    }

    {
        int oldB = score[b];
        score[b]++;

        int nextMax = curMax, nextCnt = curCnt;
        if (score[b] > curMax) {
            nextMax = score[b];
            nextCnt = 1;
        }
        else {
            if (oldB == curMax) nextCnt--;
            if (score[b] == curMax) nextCnt++;
        }

        dfs(idx + 1, nextMax, nextCnt);
        score[b]--;
    }
}

void solve() {
    cin >> n >> m >> k;
    score.assign(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        if (c == 1) {
            score[a]++;
        }
        else if (c == 2) {
            score[b]++;
        }
        else if (c == 0) {
            notMatch.push_back(make_tuple(a, b, c));
        }
    }

    ans = 0;
    int curMax = 0, curCnt = 0;
    for (int i = 1; i <= n; i++) {
        if (score[i] > curMax) {
            curMax = score[i];
            curCnt = 1;
        }
        else if (score[i] == curMax) {
            curCnt++;
        }
    }
    dfs(0,curMax, curCnt);

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    

    return 0;
}