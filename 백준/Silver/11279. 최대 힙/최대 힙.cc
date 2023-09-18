#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    priority_queue<int> maxHeap;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (x == 0) {
            if (!maxHeap.empty()) {
                cout << maxHeap.top() << '\n';
                maxHeap.pop();
            }
            else {
                cout << 0 << '\n';
            }
        }
        else {
            maxHeap.push(x);
        }
    }

    return 0;
}