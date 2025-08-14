#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <climits>
using namespace std;

typedef long long ll;

vector<ll> dp;

void dfs(int length, ll before ,ll beforeNum) {

    for (int i = beforeNum; i <= 200; i++) {
        ll temp = before + (i * i);
        if(temp < 40000) dp[temp]++;
        //cout << "temp : " << temp << '\n';
        //cout << "length : " << length << '\n';
        if (length <= 3) {
            dfs(length + 1, temp ,i);
        }
    }

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int target;
    dp.resize(40000, 0);
    dfs(1, 0,1);
    while (true) {
        cin >> target;
        if (target == 0) return 0;
        else {
            cout << dp[target] << '\n';
        }
    }

    return 0;
}
