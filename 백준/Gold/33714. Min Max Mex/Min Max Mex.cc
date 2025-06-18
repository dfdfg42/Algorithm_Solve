#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;

ll n,k;
vector<ll> vec;
map<ll, int> m;

int findMin() {
    for (int i = 0; i < 200000; i++) {
        auto it = m.find(i);
        int cnt = (it == m.end() ? 0 : it->second);
        if (cnt <= k) {
            return i;
        }
    }

    return 200000;
}

long long findMax()
{
    long long ops = k;
    long long mex = 0;


    for (auto const& pair : m)
    {
        long long val = pair.first; 

        if (val > mex)
        {
            long long gap = val - mex;
            if (ops >= gap)
            {
                ops -= gap;
                mex = val + 1;
            }
            else
            {
                return mex + ops;
            }
        }
        else if (val == mex)
        {
            mex++;
        }
    }

    return mex + ops;
}

void solve() {
    
    cin >> n >> k;
    vec.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> vec[i];
        m[vec[i]]++;

    }

    sort(vec.begin(), vec.end());

    cout << findMin() << '\n';
    cout << findMax() << '\n';

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}