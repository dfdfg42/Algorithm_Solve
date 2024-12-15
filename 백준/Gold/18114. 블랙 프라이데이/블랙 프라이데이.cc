#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, C;
    cin >> N >> C;
    vector<int> vec(N);
    for (int i = 0; i < N; i++) cin >> vec[i];

    sort(vec.begin(), vec.end());

    // 1개로 가능한지 확인
    for (int i = 0; i < N; i++) {
        if (vec[i] == C) {
            cout << 1;
            return 0;
        }
    }

    // 2개로 가능한지 확인
    {
        int left = 0, right = N - 1;
        while (left < right) {
            long long sum = (long long)vec[left] + vec[right];
            if (sum == C) {
                cout << 1;
                return 0;
            }
            else if (sum < C) {
                left++;
            }
            else {
                right--;
            }
        }
    }

    // 3개로 가능한지 확인
    // i번째 물건을 정하고, 나머지 2개 합이 C - vec[i]가 되는지 확인
    for (int i = 0; i < N; i++) {
        long long target = (long long)C - vec[i];
        int left = 0, right = N - 1;
        while (left < right) {
            if (left == i) left++;
            if (right == i) right--;
            if (left >= right) break;

            long long sum = (long long)vec[left] + vec[right];
            if (sum == target) {
                cout << 1;
                return 0;
            }
            else if (sum < target) {
                left++;
            }
            else {
                right--;
            }
        }
    }

    cout << 0;
    return 0;
}
