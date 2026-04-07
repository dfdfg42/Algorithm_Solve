#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int mod = 1'000'000'000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    //입력이 음수에 짝수면 음수
    
    int n;
    cin >> n;
    int N = abs(n);
    vector<int> dp(abs(N)+1);

    dp[0] = 0;
    dp[1] = 1;
 

    for (int i = 2; i <= N; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
    }

    
    if (N == 0) {
        cout << 0 << '\n' << 0 << '\n';
    }
    else if (N % 2 == 0 && n < 0) {
        cout <<  - 1 << '\n' << dp[N] <<'\n';
    }
    else {
        cout <<   1 << '\n' << dp[N] << '\n';
    }

    return 0;
}