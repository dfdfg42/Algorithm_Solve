#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<vector<int>> points(n,vector<int>(3));
    vector<int> players(n);

    
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < 3; j++) {
           cin >>  points[i][j];

        }
    }

    for (int j = 0; j < 3; j++) {
        map<int, int> cache;
        cache.clear();
        for (int i = 0; i < n; i++) {
            cache[points[i][j]]++;
        }
        for (int i = 0; i < n; i++) {
            if (cache[points[i][j]] == 1) {
                players[i] += points[i][j];
            }

        }
    }

    for (int i = 0; i < n; i++) {
        cout << players[i] << '\n';
    }
    
    return 0;
}
