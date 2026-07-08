#include <string>
#include <vector>
#include <climits>

using namespace std;

typedef long long ll;



int solution(int n) {
    
    int ans = 0;
    
    ll c = n;
    int c0 =0;
    int c1 =0;
    
    while(c>0 && (c & 1 ) ==0 ){
        c0 ++;
        c >>=1;
    }
    
    while(c>0 && (c&1) == 1){
        c1++;
        c >>=1;
    }
    
    
    return n + (1LL << c0) + (1LL << (c1-1)) -1;
}