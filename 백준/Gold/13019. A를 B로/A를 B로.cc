#include <iostream>
#include <algorithm>

using namespace std;


int main() {

    
    string A, B;
    cin >> A >>  B;

    int ans = 0;

    int B_index = B.length() - 1;
    for (int i = A.length()-1; i >= 0; i--) {
        if (A[i] == B[B_index]) {
            B_index --;
        }
        else ans++;

    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    if (A == B) cout << ans;
    else cout << -1;



    return 0;
}