#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;


int n;
set<ll> ansSet;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;

    queue<pair<ll, int>> q;

    q.push({ 1,1 });

    vector<ll> ans;
    while (!q.empty()) {
        pair<ll,int> now = q.front();
        //cout << now.first << '\n';
        if (now.second == n) {
            if (ansSet.find(now.first) == ansSet.end()) {
                ans.push_back(now.first);
                ansSet.insert(now.first);
            }
            q.pop();
            continue;
        }
        q.pop();


        q.push({ now.first * 2,now.second + 1 });

        ll temp = (now.first - 1) / 3;
        if(temp%2 == 1 && temp > 1 && temp*3 + 1 == now.first ){
            q.push({ temp,now.second + 1 });
        }

    }

    cout << ans.size() << '\n';

    sort(ans.begin(), ans.end());
    for (auto a : ans) {
        cout << a << '\n';
    }

    return 0;
}