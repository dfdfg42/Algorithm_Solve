#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N;
    if (!(cin >> N)) return 0;

    long long S = N * (N + 1) / 2;

    cout << S << '\n';          
    cout << S * S << '\n';     
    cout << S * S << '\n';      

    return 0;
}
