#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <string>

using namespace std;

typedef long long ll;




int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    int t;
    cin >> t;

    while (t--) {
        int v, e;
        cin >> v >> e;

        // v-e +  면 = 2
		// 2 -v + e = 면
		cout << 2 - v + e << "\n";
    }


    return 0;
}