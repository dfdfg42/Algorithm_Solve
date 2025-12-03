#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    vector<int> dp(21, 0);

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= 20; i++) {
        dp[i] = dp[i - 2] + dp[i - 1];
    }

    int n;
    cin >> n;

    string s;
    cin >> s;

    ll ans = 1; 
    int seq = 0; 

    for (int i = 0; i < n; ) { 

        if (i <= n - 4 && s[i] == 'l' && s[i + 1] == 'o' && s[i + 2] == 'n' && s[i + 3] == 'g') {
            seq++;   
            i += 4;    
        }
        else {
            if (seq > 0) {
                ans *= dp[seq];
                seq = 0; 
            }
            i++;
        }
    }

    if (seq > 0) {
        ans *= dp[seq];
    }

    cout << ans << '\n';

    return 0;
}