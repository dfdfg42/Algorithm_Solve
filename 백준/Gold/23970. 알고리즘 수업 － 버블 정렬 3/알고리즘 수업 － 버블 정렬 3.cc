#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> A(n), B(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) cin >> B[i];

    int matchCount = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] == B[i]) matchCount++;
    }
    if (matchCount == n) {
        cout << "1\n";
        return 0;
    }


    for (int last = n - 1; last >= 1; last--) {
        bool swapped = false;
        for (int i = 0; i < last; i++) {
            if (A[i] > A[i+1]) {

                if (A[i] == B[i])   matchCount--;
                if (A[i+1] == B[i+1]) matchCount--;

                swap(A[i], A[i+1]);
                swapped = true;

                if (A[i] == B[i])   matchCount++;
                if (A[i+1] == B[i+1]) matchCount++;

                if (matchCount == n) {
                    cout << "1\n";
                    return 0;
                }
            }
        }
        if (!swapped) break; 
    }

    cout << "0\n";
    return 0;
}
