#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <climits>
using namespace std;

typedef long long ll;

int n, q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    cin >> n >> q;
    vector<int> dp(n+1,1); 
    vector<int> dp2(n + 1, 1); 
    vector<int> v(n+1); //난이도
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    
    //난이도증가 dp
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (v[i] > v[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    //역순으로 난이도 하락 dp
    for (int i = n; i >= 1; i--) {
        for (int j = n; j >i ; j--) {
            if (v[i] < v[j]) {
                dp2[i] = max(dp2[i], dp2[j] + 1);
            }
        }
    }

    for (int i = 0; i < q; i++) {
        int query;
        cin >> query;
        cout << dp[query] + dp2[query] -1 << '\n';
    }

    

    return 0;
}
