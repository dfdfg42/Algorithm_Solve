#include <iostream>
#include <vector>
#include <queue>
#include <malloc.h>
#include <climits>
#include <unordered_map>
using namespace std;

const int MAX_SIZE = 101;

int parent[MAX_SIZE];
int rankArr[MAX_SIZE];

void initialize() {
    for (int x = 0; x < MAX_SIZE; x++) {
        parent[x] = x;
        rankArr[x] = 0;
    }
}

int Find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
    int A = Find(a);
    int B = Find(b);

    if (A == B) return;
    if (rankArr[A] < rankArr[B]) {
        parent[A] = B;
    }
    else if (rankArr[A] > rankArr[B]) {
        parent[B] = A;
    }
    else {
        parent[B] = A;
        rankArr[A]++;
    }
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc; cin >> tc;

    for (int i = 1; i <= tc; i++) {
        initialize();
        int n, m;
        cin >> n >> m;

        for (int j = 0; j < m; j++) {
            int a, b; cin >> a >> b;
            Union(a, b);
        }

        unordered_map<int, int> group;

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int p = Find(i);

            if (group.find(p) == group.end()) {
                group[p]++;
                ans++;
            }
            
        }

        cout << '#' << i << ' ' << ans << '\n';
    }
    

    return 0;
}
