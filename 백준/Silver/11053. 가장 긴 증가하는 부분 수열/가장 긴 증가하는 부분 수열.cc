#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {

    ios::sync_with_stdio(0); cin.tie(0);
    
    vector<int> A(1001);

    int N;
    cin >> N;
    vector<int> D(1001,1);
    int MAX = 1;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (A[j] < A[i]) {
                D[i] = max(D[i] , D[j] + 1);
                if (MAX < D[i]) {
                    MAX = D[i];
                }
            }
        }
    }

   /* for (int i = 0; i < N; i++) {
        cout << D[i] << " ";
    }*/
    cout << MAX << endl;

    return 0;
}