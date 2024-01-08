#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> liquids(N);

    for (int i = 0; i < N; ++i) {
        cin >> liquids[i];
    }
    sort(liquids.begin(), liquids.end());

    int closest = INT_MAX;
    pair<int, int> answer;

    for (int i = 0; i < N; ++i) {
        int target = liquids[i];
        int low = 0, high = N - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (mid != i) {
                int mix = liquids[mid] + target;
                if (abs(mix) < closest) {
                    closest = abs(mix);
                    answer = {min(target, liquids[mid]), max(target, liquids[mid])};
                }
            }

            if (liquids[mid] + target < 0) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }

    cout << answer.first << " " << answer.second << endl;
    return 0;
}
