#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int D, N;
    cin >> D >> N;

    vector<int> oven(D);
    for(int i = 0; i < D; i++) {
        cin >> oven[i];
        if(i > 0) 
            oven[i] = min(oven[i], oven[i-1]);
    }

    int idx = D - 1;
    for(int i = 0, pizza; i < N; i++) {
        cin >> pizza;
        while(idx >= 0 && oven[idx] < pizza) {
            idx--;
        }
        if(idx < 0) {
            cout << 0 << '\n';
            return 0;
        }
        idx--;
    }

    cout << idx + 2 << '\n';
    return 0;
}
