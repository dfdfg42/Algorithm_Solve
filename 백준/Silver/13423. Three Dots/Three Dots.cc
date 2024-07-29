#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec;

// 이진 탐색 함수
bool bs(int start, int end, int target) {
    while (start <= end) {
        int mid = (start + end) / 2;
        if (vec[mid] == target) {
            return true;
        } else if (vec[mid] > target) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vec.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> vec[i];
        }
        sort(vec.begin(), vec.end());

        int result = 0;
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                int a = vec[i];
                int b = vec[j];
                int c = 2 * b - a; // b - a == c - b 에서 유도된 공식

                if (bs(j + 1, n - 1, c)) {
                    result++;
                }
            }
        }

        cout << result << "\n";
    }

    return 0;
}
