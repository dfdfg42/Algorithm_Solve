#include <string>
#include <vector>
#include <iostream>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef long double ld;


long long solution(int n, vector<int> times) {
    
     ll ans = 0;
    sort(times.begin(), times.end());
    
    
    ll l = 0;
    ll r = LLONG_MAX;
    while(l<=r){
        //mid = 흐른 시간
        ll mid = (l+r)/2;
        
        ll cnt = 0;
        for(auto a : times){
            cnt += mid/a;
            if (cnt >= n) break;
        }
        if(cnt >= n){
            ans = mid;
            r = mid-1;
        }
        else if(cnt < n){
            l = mid+1;
        }
    }
    
    
    
    return ans;
}