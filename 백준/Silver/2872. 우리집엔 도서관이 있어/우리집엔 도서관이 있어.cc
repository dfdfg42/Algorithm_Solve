#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<int> vec;

void solve() {

    int n;
    cin >> n;
    vec.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    int seq = 0;
    for (int i = 0; i < n; i++) {
        if (vec[i] == n ) {
            
            seq++;
            int tmp = n;

            while (i >= 0 ) {
                if (vec[i] == tmp - 1) {
                    seq++;
                    tmp--;
                }

                i--;
            }

            break;
        }
    }

   // cout << "seq :" << seq << '\n';
    cout << n - seq << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();



    return 0;
}