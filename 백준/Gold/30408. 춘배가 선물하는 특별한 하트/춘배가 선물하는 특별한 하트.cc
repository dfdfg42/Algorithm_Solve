#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, M;
unordered_set<ll> seen;

bool dfs(ll cur) {
    if (cur < M) 
        return false;            
    if (cur == M) 
        return true;            
    if (!seen.insert(cur).second) 
        return false;          

    if (cur % 2 == 0) {
        
        return dfs(cur / 2);
    } else {
        
        ll low  = (cur - 1) / 2;
        ll high = low + 1;
        return dfs(low) || dfs(high);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    cout << (dfs(N) ? "YES\n" : "NO\n");
    return 0;
}