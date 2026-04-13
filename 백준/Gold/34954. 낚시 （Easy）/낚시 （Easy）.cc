#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;

int N,M;
const int INF = 987654321;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    priority_queue <int, vector<int>, greater<int>> babPq;
    priority_queue <int, vector<int>, greater<int>> fishPq;
    priority_queue <int, vector<int>, greater<int>> catchFishPq;

    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        babPq.push(a);
    }

    for (int i = 0; i < M; i++) {
        int a; cin >> a;
        fishPq.push(a);
    }


    //떡밥이 있으면 계속 잡음
    //물고기 없으면 종료

    while (!fishPq.empty()) {

        int targetFish = fishPq.top();
        fishPq.pop();

        
        if (!babPq.empty() && babPq.top() < targetFish) {
            babPq.pop();
            catchFishPq.push(targetFish);
        }
        else if (!catchFishPq.empty() && catchFishPq.top() < targetFish) {
            catchFishPq.pop();
            catchFishPq.push(targetFish); 
        }
        

        
    }
    
    ll ans = 0;
    while (!catchFishPq.empty()) {
        ans += catchFishPq.top();
        catchFishPq.pop();
    }

    cout << ans << '\n';

    return 0;
}