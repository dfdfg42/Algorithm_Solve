#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;

int n;
vector<vector<int>> countMap;
vector<vector<char>> mineMap;
int mineCount;

bool checkZero(int y, int x) {
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;

            int ny = y + i;
            int nx = x + j;

            if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

            if (isdigit(mineMap[ny][nx])) {
                if (mineMap[ny][nx] == '0') {
                    return false;
                }
            }
        }
    }
    return true;
}
void landMine(int y, int x) {
    mineCount++;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;

            int ny = y + i;
            int nx = x + j;

            if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
            if (isdigit(mineMap[ny][nx])) {
                mineMap[ny][nx]--;
            }
        }
    }
}

void solve() {
    cin >> n;
    mineCount = 0;
    countMap.resize(n, vector<int>(n));
    mineMap.resize(n, vector<char>(n ,'#'));
    
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j <n; j++) {
            mineMap[i][j] = s[j];
        }
    }
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            if (checkZero(i,j)) {
                landMine(i, j);
            }
        }
    }


    cout << mineCount << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}