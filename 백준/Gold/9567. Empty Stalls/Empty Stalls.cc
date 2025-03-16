#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <map>
#include <climits>
#include <vector>

using namespace std;


typedef long long ll;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<ll> stallWait(n,0);
    vector<bool> cowIsIn(n, false);

    for (int i = 0; i < k; i++) {
        ll x, y, a, b;
        cin >> x >> y >> a >> b;

        //그 목초지의 대기 소 추가
        for (ll j = 1; j <= y; j++) {
            ll temp = ((a * j) + b) % n;
            stallWait[temp] += x;
            //cout << "temp :" << temp << '\n';
        }
    }


    //두번정도 돌면 전부 해소할거같음
    ll cowStack = 0;
    int minNumStall = INT_MAX;
    for (int i = 0; i < 2; i++) {

        for (int j = 0; j < n; j++) {
            if (stallWait[j] != 0) {
                cowStack += stallWait[j];
                stallWait[j] = 0;
            }
            if (cowIsIn[j] == false && cowStack >0) {
                cowStack--;
                cowIsIn[j] = true;

                //cout << j << ' ';
            }
            
        }
        
    }
    
    
    for (int i = 0; i < n; i++) {
        if (cowIsIn[i] == false) {
            minNumStall = i;
            break;
        }
    }

    cout << minNumStall << '\n';

    return 0;
}
