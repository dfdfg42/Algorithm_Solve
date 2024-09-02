#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

vector<int> levels;

bool makeLevel(int k,int targetLevel) {
    

    for (int i = 0; i < levels.size(); i++) {
        if (levels[i] < targetLevel) {
            int cost = targetLevel - levels[i];

            if (k < cost) {
                return false;
            }
            else {
                k -= cost;
            }
        }
    }

    return true;

}


int main() {

    int n, k;
    
    cin >> n >> k;

    levels.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> levels[i];
    }

    sort(levels.begin(), levels.end());

    

    int l = 1;
    int r = levels[n - 1] + k;
    int maxLevel = 0;

    while (l <= r) {
        int mid = (l + r) / 2;
        
        if (makeLevel(k,mid)) {
            maxLevel = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }


    }

    cout << maxLevel << '\n';

    
    return 0;
}
