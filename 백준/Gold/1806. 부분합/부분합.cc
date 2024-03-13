#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    int start = 0, end = 0, sum = 0;
    int minlength = INT_MAX;

    while (end < N) {
        // Add to sum until it's greater than or equal to M
        while (end < N && sum < M) {
            sum += nums[end++];
        }

        // Shrink subarray from the start to find the smallest length
        while (sum >= M) {
            minlength = min(minlength, end - start);
            sum -= nums[start++];
        }
    }

    // Check if minlength was updated, else return 0 as no such subarray exists
    if (minlength == INT_MAX) {
        minlength = 0;
    }

    cout << minlength << '\n';

    return 0;
}
