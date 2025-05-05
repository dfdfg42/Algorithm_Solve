#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> rank(n+1), t(n+1);
    int maxr = 0;
    for(int i = 1; i <= n; i++){
        cin >> rank[i] >> t[i];
        maxr = max(maxr, rank[i]);
    }

    // 계급별 컴퓨터 모으기
    vector<vector<int>> grp(maxr+1);
    for(int i = 1; i <= n; i++){
        grp[rank[i]].push_back(i);
    }

    // finish[i]: i번 컴퓨터가 완전히 종료되는 시간
    vector<ll> finish(n+1, 0);

    // 계급 1 처리
    for(int i : grp[1]){
        finish[i] = t[i];
    }

    // 계급 2 이상 처리
    for(int r = 2; r <= maxr; r++){
        for(int j : grp[r]){
            ll startTime = 0;
            // 모든 이전 계급 컴퓨터로부터의 정보 수신 완료 시점
            for(int i : grp[r-1]){
                ll arrival = finish[i] + 1LL * (i - j) * (i - j);
                startTime = max(startTime, arrival);
            }
            finish[j] = startTime + t[j];
        }
    }

    // 최종 답: 모든 컴퓨터 중 최대 종료 시간
    ll answer = 0;
    for(int i = 1; i <= n; i++){
        answer = max(answer, finish[i]);
    }
    cout << answer;
    return 0;
}
