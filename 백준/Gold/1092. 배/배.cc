#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <queue>
#include <unordered_map>
#include <tuple>
#include <algorithm>
#include <map>
#include <deque>


using namespace std;

typedef long long ll;

int n, m;

vector<int> crains;
vector<int> boxes;

void solve() {

    cin >> n;
    crains.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> crains[i];
    }
    sort(crains.begin(), crains.end(),greater<>());

    cin >> m;
    boxes.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> boxes[i];
        if (boxes[i] > crains[0]) {
            cout << -1 << '\n';
            return;
        }
    }
    sort(boxes.begin(), boxes.end(),greater<>());

    if (boxes.empty()) {
        cout << 0 << '\n';
        return;
    }
    int time = 0;
    while (!boxes.empty()) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < boxes.size(); j++) {
                if (!boxes.empty() && boxes[j] <= crains[i]) {
                    boxes.erase(boxes.begin() + j);
                    break;
                }
            }
        }
        time++;
        if (boxes.empty()) {
            cout << time << '\n';
            return;
        }

    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();



    return 0;
}