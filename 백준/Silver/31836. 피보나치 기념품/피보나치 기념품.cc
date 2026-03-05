#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    vector<int> A, B;
    int curr = N;

    while (curr >= 3) {
        A.push_back(curr);     
        B.push_back(curr - 1); 
        B.push_back(curr - 2); 
        curr -= 3;
    }

    if (curr == 2) {
        A.push_back(2);
        B.push_back(1);
    }

    cout << A.size() << "\n";
    for (int i = 0; i < A.size(); ++i) {
        cout << A[i] << (i == A.size() - 1 ? "" : " ");
    }
    cout << "\n";

    cout << B.size() << "\n";
    for (int i = 0; i < B.size(); ++i) {
        cout << B[i] << (i == B.size() - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}