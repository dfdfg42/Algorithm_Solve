#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <queue>
#include <unordered_map>
#include <tuple>
#include <algorithm>
#include <map>


using namespace std;

typedef long long ll;

int n, k;
int maxGam;
vector<int> A;
vector<int> B;
vector<int> C;
vector<bool> visited;

void dfs(int cnt, vector<bool>& visited ,int  prev_idx ,int totalGam) {
    if (cnt == n-1 ) {
        maxGam = max(maxGam, totalGam);
    }

    for (int i = 0; i < n; i++) {
        if (visited[i] == false) {
            if (C[prev_idx] * C[i] <= k) {
                visited[i] = true;
                dfs(cnt + 1, visited, i, totalGam + A[prev_idx] * B[i]);
                visited[i] = false;
            }
        }
    }
}

void solve() {

    cin >> n >> k;
    A.assign(n,0);
    B.assign(n, 0);
    C.assign(n, 0);
    visited.assign(n, false);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> C[i];
    }

    maxGam = 0;
    for (int i = 0; i < n; i++) {
        visited[i] = true;
        dfs(0, visited, i, 0);
        visited[i] = false;
    }
    if (maxGam == 0) {
        cout << -1 << '\n';
    }else
    cout << maxGam << '\n';
    

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    

    return 0;
}