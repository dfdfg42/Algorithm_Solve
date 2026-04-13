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

    while (!babPq.empty()) {

        int nowBap = babPq.top();
        babPq.pop();

        //잡을 물고기 없으면 종료
        if (fishPq.empty()) {
            break;
        }

        if (fishPq.top() > nowBap) {
            catchFishPq.push(fishPq.top());
            fishPq.pop();
        }
        else {
            //가장 작은 떡밥보다 큰 물고기가 없으므로 종료
            break;
        }

        //만약 떡밥이 비어있고 물고기로 더 큰 물고기를 잡을수 있으면
        //떡밥으로 만듬
        if (babPq.empty() && !catchFishPq.empty() && !fishPq.empty()) {

            int tempBab = catchFishPq.top();
            catchFishPq.pop();
            babPq.push(tempBab);
;
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