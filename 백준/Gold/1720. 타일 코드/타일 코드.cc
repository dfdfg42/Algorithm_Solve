#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    int n;
    cin >> n;

    vector<int> dp(n + 1, 0);

    dp[0] = dp[1] =  1;
  


    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + (dp[i - 2] * 2);
    }

    if (n % 2 == 0) { //짝수
        cout << (dp[n] + dp[(n / 2) - 1] * 2 + dp[n / 2])/2 << '\n';
    }
    else { //홀수
        cout << (dp[n] + dp[(n - 1) / 2])/2 << '\n';
    }


}
