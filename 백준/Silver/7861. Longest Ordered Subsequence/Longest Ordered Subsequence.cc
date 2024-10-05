#include <iostream>
#include <vector>

using namespace std;





int main() {
    
    int n;
    cin >> n;

    vector<int> vec(n);

    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }


    vector<int> dp(n,1);
    int maxlen = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i ; j++) {
            if (vec[i] > vec[j] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                maxlen = max(dp[i], maxlen);
            }
        }
    }

    cout << maxlen << '\n';

    return 0;
}
