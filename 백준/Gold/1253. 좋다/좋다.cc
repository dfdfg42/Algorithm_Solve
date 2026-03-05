#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

vector<ll> v;
int N;



bool findGood(int index) {


    int target = v[index];
    int l = 0, r =N-1;
    int cnt = 0;
    while (l < r) {

        if (v[l] + v[r] == target) {
            if (l == index) {
                l++;
            }
            else if (r == index) {
                r--;
            }
            else {
                return true;
            }
        }
        else if (v[l] + v[r] < target) {
            l++;
        }
        else if (v[l] + v[r] > target) {
            r--;
        }


    }

    return false;

}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> N;

    v.resize(N);
    int ans = 0;

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < N; i++) {

        if (findGood(i)) ans++;

    }

    cout << ans << '\n';

    return 0;
}