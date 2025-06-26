#include <iostream>
#include <vector>

using namespace std;

vector<int> vec;
vector<bool> visited;

void solve() {
    int n;
    cin >> n;

    vec.resize(n);
    visited.resize(7, false);
    visited[0] = true;
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
        vector<bool> temp = visited;

        for (int j = 0; j < 7; j++) {
            if (visited[j]) {
                temp[(vec[i] + j) % 7] = true;
            }

        }
        visited = temp;
    }

    if (visited[4]) {
        cout << "YES" << '\n';
    }
    else {
        cout << "NO" << '\n';
    }
    
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    

    return 0;
}