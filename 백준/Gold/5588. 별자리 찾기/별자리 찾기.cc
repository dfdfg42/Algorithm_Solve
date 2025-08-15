#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <climits>
using namespace std;

typedef long long ll;

vector<pair<int, int>> ori_star;
set<pair<int, int>>my_star;
vector<pair<int, int>> diff;

bool findMatch(int a, int b) {
    for (auto s : ori_star) {
        if (my_star.find({ s.first - a , s.second - b }) != my_star.end())continue;
        else return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        ori_star.push_back({ a,b });
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        my_star.insert({ a,b });
        diff.push_back({ ori_star[0].first - a , ori_star[0].second - b });
    }
    for (auto a : diff) {
        if (findMatch(a.first, a.second)) {
            cout << a.first * -1 << ' ' << a.second * -1 << '\n';
            return 0 ;
        }
    }

    

    return 0;
}
