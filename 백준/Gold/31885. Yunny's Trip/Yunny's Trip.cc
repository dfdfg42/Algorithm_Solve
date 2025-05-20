#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct P { ll x,y; };
static const ll INF = (ll)1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    ll K;
    cin >> N >> K;

    vector<P> items(N);
    for(int i=0;i<N;i++){
        cin >> items[i].x >> items[i].y;
    }
    ll ex, ey;
    cin >> ex >> ey;

    ll ans = INF;

    // p = 0
    ll E0 = llabs(ex) + llabs(ey);
    if(E0 <= K) ans = min(ans, E0);

    // p = 1
    if(K >= 2){
        for(auto &it: items){
            ll dx = llabs(ex - it.x);
            ll dy = llabs(ey - it.y);
            ll Di = dx + dy;
            ll Ei = 2 + Di;
            if(Ei <= K) ans = min(ans, Ei);
        }
    }

    // p = 2
    if(K >= 4){
        // 해시맵에 모든 아이템 등록 (무한 반복 허용이므로 count 상관 없음)
        unordered_map<ll, unordered_set<ll>> mp;
        mp.reserve(N*2);
        for(auto &it: items){
            mp[it.x].insert(it.y);
        }

        // (a) q=0 → 합이 (ex,ey)
        for(auto &it: items){
            ll needX = ex - it.x;
            ll needY = ey - it.y;
            auto itX = mp.find(needX);
            if(itX != mp.end() && itX->second.count(needY)){
                ans = min(ans, 4LL);
                break;
            }
        }
        // (b) q=1 → 합이 맨해튼 이웃
        if(K >= 5){
            static const ll dx4[4] = {1,-1,0,0};
            static const ll dy4[4] = {0,0,1,-1};
            for(auto &it: items){
                for(int d=0;d<4;d++){
                    ll Sx = ex + dx4[d] - it.x;
                    ll Sy = ey + dy4[d] - it.y;
                    auto itX = mp.find(Sx);
                    if(itX != mp.end() && itX->second.count(Sy)){
                        ans = min(ans, 5LL);
                        goto OUT;
                    }
                }
            }
        }
        OUT: ;
    }

    cout << (ans==INF ? -1 : ans) << "\n";
    return 0;
}
