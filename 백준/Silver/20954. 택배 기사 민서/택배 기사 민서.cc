#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        long long x;
        cin >> x;

        if(x == 0){
            cout << 0 << "\n";
            continue;
        }

        long long absX = llabs(x);
        long long expo = 0;

        while((1LL << expo) < absX){
            expo++;
        }

        if(x > 0){

            long long ans = (5LL * ((long long)1 << expo) - 4LL)
                            - (((long long)1 << expo) - x);
            cout << ans << "\n";
        } else {

            long long ans = (5LL * ((long long)1 << expo) - 4LL)
                            + ((long long)1 << (expo+1))
                            - (((long long)1 << expo) - absX);
            cout << ans << "\n";
        }
    }

    return 0;
}