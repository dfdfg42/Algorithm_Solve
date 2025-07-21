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

ll n, h, t;


void solve() {

    cin >> n >> h >> t;
    
    priority_queue<int, vector<int>> pq;

    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;

        pq.push(input);
    }

    int cnt = 0;
    while (t > 0) {
        ll top = pq.top();
        //cout << " top : " << top << endl;
        if (top < h) {
            break;
        }
        else if (top == 1) {
            break;
        }
        else {
            top /= 2;
        }
        pq.pop();
        pq.push(top);
        cnt++;
        t--;
    }

    if (pq.top() < h) {
        cout << "YES" << '\n';
        cout << cnt << '\n';
    }
    else {
        cout << "NO" << '\n';
        cout << pq.top() << '\n';
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    

    return 0;
}