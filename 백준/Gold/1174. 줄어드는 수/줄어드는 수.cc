#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <queue>
#include <unordered_map>
#include <tuple>
#include <algorithm>
#include <map>
#include <deque>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;
typedef long long ll;

//줄어드는지 확인 
int decrease(ll now) {

    string s = to_string(now);
    
    //감소하는 부근 건너뛰기 위해 더해줄값 반환
    for (int i = 1; i < s.length(); i++) {
        if (s[i] - '0' >= s[i - 1] - '0') {
            int digit = pow(10, s.length() - i-1);
            return digit;
        }
    }

    //cout << "true : " << now << '\n';
    return -1;
}

void solve() {

    int n;
    cin >> n;

    int cnt = 0;

    ll now = 0;

    while (cnt < n && now < 100'000'00001) {
        
        int temp = decrease(now);
        if (temp == -1) {
            cnt++;

            if (cnt == n) {
                break;
            }
            now++;
        }
        else {
            now += temp;
        }

    }

    if (cnt == n) {
        cout << now << '\n';
    }
    else {
        cout << -1 << '\n';
    }


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}