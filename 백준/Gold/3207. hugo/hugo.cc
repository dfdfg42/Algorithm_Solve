#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
        ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N; // Number of squares

    vector<vector<int>> apples(100001); // Vector to store apple fall times
    int max_time = 0; // Track the maximum time apple falls

    // Read apple fall times
    for (int i = 1; i <= N; ++i) {
        int K;
        cin >> K;
        for (int j = 0; j < K; ++j) {
            int t;
            cin >> t;
            apples[t].push_back(i); // Store the position where apple falls at time t
            max_time = max(max_time, t); // Update maximum time
        }
    }

    // Initialize DP arrays for the current and previous time step
    vector<int> dp_prev(N + 1, -1), dp_current(N + 1);
    dp_prev[(N + 1) / 2] = 0; // Hugo starts in the middle

    // Dynamic programming to calculate maximum apples caught
    for (int t = 1; t <= max_time; ++t) {
        fill(dp_current.begin(), dp_current.end(), -1);
        for (int p = 1; p <= N; ++p) {
            if (dp_prev[p] != -1) {
                // Stay in place
                int applesCaught = dp_prev[p] + (find(apples[t].begin(), apples[t].end(), p) != apples[t].end());
                dp_current[p] = max(dp_current[p], applesCaught);

                // Move left
                if (p > 1) dp_current[p - 1] = max(dp_current[p - 1], applesCaught);

                // Move right
                if (p < N) dp_current[p + 1] = max(dp_current[p + 1], applesCaught);
            }
        }
        dp_prev = dp_current; // Prepare for the next time step
    }

    // The result is the maximum value in the last DP array
    cout << *max_element(dp_prev.begin(), dp_prev.end()) << endl;

    return 0;
}
