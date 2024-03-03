#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> flasks(N);
    for (int i = 0; i < N; i++) {
        cin >> flasks[i];
    }

    sort(flasks.begin(), flasks.end());

    int left = 0, right = N - 1;
    int closestSum = INT_MAX;
    int answerLeft = 0, answerRight = 0;

    while (left < right) {
        int sum = flasks[left] + flasks[right];

        if (abs(sum) < abs(closestSum)) {
            closestSum = sum;
            answerLeft = left;
            answerRight = right;
        }

        if (sum < 0) {
            left++;
        }
        else {
            right--;
        }
    }

    cout << flasks[answerLeft] << " " << flasks[answerRight] << "\n";

    return 0;
}
