#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

typedef long long ll;

int N, M;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    priority_queue<int, vector<int>, greater<int>> babPq;
    priority_queue<int, vector<int>, greater<int>> fishPq;
    priority_queue<int, vector<int>, greater<int>> catchFishPq;

    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        babPq.push(a);
    }

    for (int i = 0; i < M; i++) {
        int a; cin >> a;
        fishPq.push(a);
    }

    vector<string> commands;

    while (!fishPq.empty()) {
        int targetFish = fishPq.top();
        fishPq.pop();

        if (!babPq.empty() && babPq.top() < targetFish) {
            commands.push_back("fish " + to_string(babPq.top()));
            babPq.pop();
            catchFishPq.push(targetFish);
        }
        else if (!catchFishPq.empty() && catchFishPq.top() < targetFish) {
            commands.push_back("bait " + to_string(catchFishPq.top()));
            commands.push_back("fish " + to_string(catchFishPq.top()));
            catchFishPq.pop();
            catchFishPq.push(targetFish); 
        }
    }
    
    ll ans = 0;
    while (!catchFishPq.empty()) {
        ans += catchFishPq.top();
        catchFishPq.pop();
    }

    cout << commands.size() << '\n';

    for (int i = 0; i < commands.size(); i++) {
        cout << commands[i] << '\n';
    }

    cout << ans << '\n';

    return 0;
}