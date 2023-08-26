#include <iostream>
#include <vector>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int dp[5000] = { 0, };
    int arr[5000];

    string input;
    cin >> input;

    if (input.length() == 1 && input[0] == '0') {
        cout << 0;
        return 0;
    }
    for (int i = 1; i <= input.length(); i++) {
        arr[i] = input[i - 1] - '0';
    }

    dp[0] = 1;
    for (int i = 1; i <= input.length(); i++) {
        if (arr[i] != 0) {
            dp[i] = dp[i] + dp[i - 1]%10000000;
        }

        if (i == 1) continue;
        int x = arr[i] + arr[i - 1] * 10;

        if (10 <= x && x <= 26) {
            dp[i] = (dp[i - 2] + dp[i]) % 1000000;
        }
    }

    cout << dp[input.length()];

    return 0;
}
