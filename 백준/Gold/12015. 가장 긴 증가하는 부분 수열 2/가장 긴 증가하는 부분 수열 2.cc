#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    vector<int> A(N), LIS;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++) {
        auto it = lower_bound(LIS.begin(), LIS.end(), A[i]);
        if (it == LIS.end()) {
            LIS.push_back(A[i]);
        } else {
            *it = A[i];
        }
    }

    cout << LIS.size() << '\n';
    return 0;
}
