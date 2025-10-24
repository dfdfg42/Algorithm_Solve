#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>   
#include <algorithm>
#include <queue>

using namespace std;

struct comp {

    bool operator()(const pair<int, int>& x, const pair<int, int>& y) const {
        if (x.first != y.first) return x.first > y.first;   
        return x.second > y.second; 
    }

};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    
    int n;
    cin >> n;

    priority_queue<pair<int, int>,vector<pair<int,int>> ,comp>  pq;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        pq.push({ a,1 });
        pq.push({ b,-1 });

    }

    int ans = 0;
    int now = 0;

    while (!pq.empty()) {
        now += pq.top().second;
        ans = max(ans, now);
        pq.pop();

    }
    
    cout << ans << '\n';

    return 0;
}