#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;


vector<int> coins;

int greedy(int value, vector<int>& coins) {

    int count = 0;
    int remaining = value;

    for (int i = coins.size() - 1; i >= 0; i--) {
        if (coins[i] <= remaining) {
            int num = remaining / coins[i];
            count += num;
            remaining -= coins[i] * num;

        }
        if (remaining == 0) {
            break;
        }



    }

    return count;

}



int main() {

    int n;
    cin >> n;

    coins.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    sort(coins.begin(), coins.end());

    int max_x = coins[n - 2] + coins[n - 1];

    vector<int> dp(max_x + 1, max_x + 1);
    dp[0] = 0;

    for (int i = 1; i <= max_x; i++) {
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
            else {
                break;
            }
        }
    }

    bool isCanonical = true;

    for (int x = 1; x <= max_x; ++x) {
        int greedy_count = greedy(x, coins);
        if (greedy_count > dp[x]) {
            isCanonical = false;
            break;
        }

    }


    if (isCanonical) {
        cout << "Yes" << '\n';
    }
    else {
        cout << "No" << '\n';
    }

    return 0;
}
