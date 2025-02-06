#include <iostream>
#include <vector>
#include <queue>
#include <malloc.h>
#include <climits>
#include <unordered_map>
using namespace std;



int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;

    for (int i = 1; i <= tc; i++) {
        int n; cin >> n;
        priority_queue<int> pq;
        
        cout << '#' << i <<' ';
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a;
            if (a == 1) {
                cin >> b; 
                pq.push(b);
            }
            else if(a==2) {
                if (!pq.empty()) {
                    cout << pq.top() << ' ';
                    pq.pop();
                }
                else {
                     cout  << -1 << ' ';
                }
            }
        }
        
        cout << '\n';

        while (!pq.empty())
            pq.pop();

    }
    

    return 0;
}
