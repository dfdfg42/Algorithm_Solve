#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <set>
#include <cmath>
using namespace std;

typedef long long ll;
typedef long double ld;

void solve() {

    int n;
    cin >> n;
    vector<vector<bool>> dp(n + 1, vector<bool>(7,false));

    dp[0][1] = true;
    for (int i = 1; i <= n; i++) {

        char ops1;
        cin >> ops1;

        int input1;
        cin >> input1;

        char ops2;
        cin >> ops2;

        int input2;
        cin >> input2;

        for (int j = 0; j < 7; j++) {
            if (dp[i - 1][j]) {
                if (ops1 == '+') {
                    dp[i][(j + input1) % 7] = true;
                }
                else if (ops1 == '*') {
                    dp[i][(j * input1) % 7] = true;
                }
            }

            if (dp[i - 1][j]) {
                if (ops2 == '+') {
                    dp[i][(j + input2) % 7] = true;
                }
                else if (ops2 == '*') {
                    dp[i][(j * input2) % 7] = true;
                }
            }
        }

    }

    if (dp[n][0]) {
        cout << "LUCKY" << '\n';
    }
    else {
        cout << "UNLUCKY" << '\n';
    }

}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    //dp or 그리디  ->  dp 일경우 나타내야 되는 상태 
    // K % 7은 0~7까지밖에없다 
    // dp[i][j] = i 번째 턴이 끝났을때  k를 j로 나눈수가 i가 되는게 가능

    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    

    
    return 0;
}