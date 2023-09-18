#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    priority_queue<int,vector<int>,greater<int>> minHeap;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (x == 0) {
            if (!minHeap.empty()) {
                cout << minHeap.top() << '\n';
                minHeap.pop();
            }
            else {
                cout << 0 << '\n';
            }
        }
        else {
            minHeap.push(x);
        }
    }

    return 0;
}