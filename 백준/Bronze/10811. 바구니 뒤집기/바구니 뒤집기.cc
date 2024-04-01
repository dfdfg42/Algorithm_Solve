#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <iomanip>
#include <tuple>
#include <sstream>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;
    vector<int> vec(n+1);
    for (int i = 1; i <= n; i++) {
        vec[i] = i;
    }

    for (int k = 0; k < m; k++) {
        int i, j;
        cin >> i >> j;
        reverse(vec.begin()+i, vec.begin()+ j+ 1);
    }

    for (int i = 1; i <= n; ++i) {
        cout << vec[i] << ' ';
    }
    cout << endl;



    
    return 0;
}
