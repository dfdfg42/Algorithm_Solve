#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <tuple>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    
    cin >> n >> k;
    vector<int> whites(n);

    for (int i = 0; i < n; i++) {
        cin >> whites[i];
    }



    int ans = 0;

    int r =  whites[0] ,l = whites[0];
    for (int i = 1; i < whites.size(); i++) {

        if (r < whites[i]) {
            r = whites[i];
        }
        else if (l > whites[i]) {
            l = whites[i];
        }

        //cout << "whites[i] :" << whites[i] << " \nl:" << l << " r:" << r << " ans: "<<ans << '\n';

        if ((r-l)>= k) {
   
            ans++;
            r = l = whites[i];
        }
    }

    cout << ans << '\n';

    return 0;
}
