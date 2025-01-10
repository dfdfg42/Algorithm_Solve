#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int n;
int check(int start, int gap, const vector<int>& vec, int initial_count) {
    int count = initial_count;

    for (int i = 0; i < n; i++) {
        int expected = start + gap * i;
        int actual = vec[i];
        if (abs(expected - actual) > 1) {
            return INT_MAX;
        }
        if (expected != actual) {
            count++;
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    vector<int> vec(n);
    for (int& x : vec) cin >> x;

    if (n == 1) {
        cout << 0;
        return 0;
    }

    int ans = INT_MAX;

    for (int d1 = -1; d1 <= 1; d1++) {
        for (int d2 = -1; d2 <= 1; d2++) {
    
            int first = vec[0] + d1;
            int second = vec[1] + d2;
     
            if ((second - first) % 1 != 0) { // 공차는 정수임
              
            }
            int gap = second - first;
   
            int count = 0;
            if (d1 != 0) count++;
            if (d2 != 0) count++;
         
            bool valid = true;
            for (int i = 2; i < n; i++) {
                int expected = first + gap * i;
                int actual = vec[i];
                if (abs(expected - actual) > 1) {
                    valid = false;
                    break;
                }
                if (expected != actual) {
                    count++;
                }
            }
            if (valid) {
                ans = min(ans, count);
            }
        }
    }

    if (ans == INT_MAX) {
        cout << -1;
    }
    else {
        cout << ans;
    }
}
