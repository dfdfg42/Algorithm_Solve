#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <iomanip>
#include <tuple>
#include <sstream>
#include <map>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (x == 0) {
            if (pq.empty()) {
                cout << '0' << '\n';
            }
            else {
                cout << pq.top().second << '\n';
                pq.pop();
            }
        }
        else {
            pq.push({ abs(x),x });
        }


    }
    
    return 0;
}
