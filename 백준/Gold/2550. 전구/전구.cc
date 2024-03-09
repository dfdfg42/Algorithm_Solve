#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> switches(N+1), bulbs(N+1), positions(N+1), dp(N+1), prev(N+1);
    for (int i = 1; i <= N; ++i) {
        cin >> switches[i];
    }
    for (int i = 1; i <= N; ++i) {
        int bulb;
        cin >> bulb;
        positions[bulb] = i;
    }
    for (int i = 1; i <= N; ++i) {
        bulbs[i] = positions[switches[i]];
    }

    fill(dp.begin(), dp.end(), 1);
    int maxLen = 0, lastIndex = 0;
    for (int i = 1; i <= N; ++i) {
        prev[i] = -1;
        for (int j = 1; j < i; ++j) {
            if (bulbs[j] < bulbs[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
        if (dp[i] > maxLen) {
            maxLen = dp[i];
            lastIndex = i;
        }
    }

    cout << maxLen << endl;

    vector<int> sequence;
    while (lastIndex != -1) {
        sequence.push_back(switches[lastIndex]);
        lastIndex = prev[lastIndex];
    }

    sort(sequence.begin(), sequence.end());
    for (int i = 0; i < sequence.size(); ++i) {
        cout << sequence[i] << " ";
    }

    return 0;
}
