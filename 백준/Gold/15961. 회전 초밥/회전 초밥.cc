#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, d, k, c;
    cin >> N >> d >> k >> c;

    vector<int> sushi(N);
    vector<int> sushiCount(d + 1, 0);  // Use vector instead of array and +1 for 1-based index

    for (int i = 0; i < N; i++) {
        cin >> sushi[i];
    }

    int sushiType = 0;
    int maxType = 0;

    // Initialize the first window
    for (int i = 0; i < k; i++) {
        if (sushiCount[sushi[i]]++ == 0) {
            sushiType++;
        }
    }

    maxType = sushiType;

    // Slide the window
    for (int i = 1; i < N; i++) {
        // Move out the leftmost sushi
        if (--sushiCount[sushi[i - 1]] == 0) {
            sushiType--;
        }

        // Move in the rightmost sushi (circularly)
        if (sushiCount[sushi[(i + k - 1) % N]]++ == 0) {
            sushiType++;
        }

        // Check for the free coupon sushi
        if (sushiCount[c] == 0) {
            maxType = max(maxType, sushiType + 1);
        }
        else {
            maxType = max(maxType, sushiType);
        }
    }

    cout << maxType;

    return 0;
}
