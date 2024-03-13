#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    int end = 0, start = 0,sum = 0;
    int minlength = INT_MAX;

    while (end < N) {

        if (sum < M) {
            sum += nums[end++];
        }
        while(sum >= M) {
            minlength = min(minlength, end - start);
            sum -= nums[start++];

        }
    }

    if (minlength == INT_MAX) minlength = 0;

    cout << minlength << '\n';
}

