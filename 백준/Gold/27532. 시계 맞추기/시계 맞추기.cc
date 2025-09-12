#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <cstring>
#include <set>
#include <cmath>
#include <climits>
#include <algorithm>


using namespace std;

typedef long long ll;
typedef long double ld;

int m;
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m;
    n = INT_MAX;
    
    vector<int> clocks(m);
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        clocks[i] = (stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2)));
    }

    for (int i = 1; i <= 720; i++) {
        set<int> possible;

        for (int j = 0; j < m; j++) {
            int time = clocks[j];
            int fingerprint = (time - j * i) % 720;
            if (fingerprint < 0) fingerprint += 720;
            possible.insert(fingerprint);
        }

        n = min(n, (int)possible.size());
    }
    
    cout << n << '\n';

    return 0;
}