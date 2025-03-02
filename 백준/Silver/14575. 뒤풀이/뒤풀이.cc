#include <iostream>
#include <climits>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t;
    cin >> n >> t;

    vector<int> L(n);
    vector<int> R(n);


    ll sumL = 0, sumR = 0;
    ll maxL = 0;  
    for (int i = 0; i < n; i++) {
        cin >> L[i] >> R[i];
        sumL += L[i];
        sumR += R[i];
        if (L[i] > maxL) maxL = L[i];
    }

    if (sumL > t || sumR < t) {
        cout << -1 << '\n';
        return 0;
    }

    int l = 0, r = 1e9;

    int mid;
    int ans;
    while (l <= r) {

        mid = (r + l) / 2;

        bool possible = true;
        int sum = 0; //최소로 필요한 맥주량
        int dum = 0; //더 줄수 있는 맥주량
        for (int i = 0; i < n; i++) {
            if (L[i] > mid) {
                possible = false;
                break;
            }
            sum += L[i];
            if (R[i] < mid) {
                dum += R[i] - L[i];
            }
            else {
                dum += mid - L[i];
            }

        }

 

        if (sum + dum >= t && possible) {
            ans = mid;
            r = mid - 1; 
        }
        else {
            l = mid + 1;
        }
    }
    
    cout << ans;

    return 0;
}

