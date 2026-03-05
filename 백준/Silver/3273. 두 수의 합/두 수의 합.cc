#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    
    int n,x;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    cin >> x;


    int l = 0,r= n-1;
    int ans = 0;
    while (l < r) {

        if (v[r] + v[l] == x) {
            ans++;
            l++;
        }else if (v[r] + v[l] < x) {
            l++;
        }
        else if (v[r] + v[l] > x) {
            r--;
        }

        

    }

    cout << ans << '\n';

    return 0;
}