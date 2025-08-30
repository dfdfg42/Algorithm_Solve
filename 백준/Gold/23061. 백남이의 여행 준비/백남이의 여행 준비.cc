#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <cstring>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n, m;
    cin >> n >> m;

    //무게,가치
    vector<pair<int,int>> items(n);

    for (int i = 0; i < n; i++) {
        cin >> items[i].first >> items[i].second;
    }

    vector<int> bags(m);
    int maxSize = 0;
    for (int i = 0; i < m; i++) {
        cin >> bags[i];
        maxSize = max(bags[i], maxSize);
    }

    vector<int> dp(maxSize+1,0);
    for (int i = 0; i < n; i++) {
        int w = items[i].first;
        int v = items[i].second;
        for (int W = maxSize; W >= w; W--) {
            dp[W] = max(dp[W], dp[W - w] + v);
        }
    }

    ld ans =  -1;
    int ansIndex = 0;
    for (int i = 0; i < bags.size(); i++) {

        if ((ld)dp[bags[i]] / (ld)bags[i] > ans) {
            ansIndex = i;
            ans = (ld)dp[bags[i]] / (ld)bags[i];
        }
    }

  

    cout << ansIndex + 1 << '\n';
    
    return 0;
}