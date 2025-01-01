#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; 
    cin >> N;

    while (N--) {
        long long X;
        cin >> X;


        long long r = (long long)floorl(sqrtl((long double)X));


        if (r * r == X) {
   
            cout << 1 << " ";
        }
        else {
            cout << 0 << " ";
        }
    }
    cout << "\n";
    return 0;
}
