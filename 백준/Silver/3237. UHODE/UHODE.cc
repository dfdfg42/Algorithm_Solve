#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

int ry[9] = { 1, 1, 1, 0, 0, -1, -1, -1, 0 };
int rx[9] = { -1, 0, 1, -1, 1, -1, 0, 1, 0 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // 좌표에 해당하는 모든 스파이 번호를 저장
    map<pair<int, int>, vector<int>> spyMap;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        spyMap[{x, y}].push_back(i);
    }

    int k;
    cin >> k;
    string s;
    cin >> s;
    pair<int, int> now = { 0, 0 };

    set<int> heardSpies;

    // 시작점 (0,0)에서 주변 9칸 검사
    for (int i = 0; i < 9; i++) {
        pair<int, int> next = { now.first + rx[i], now.second + ry[i] };
        if (spyMap.find(next) != spyMap.end()) {
            for (int spy : spyMap[next]) {
                heardSpies.insert(spy);
            }
        }
    }

    // 이동하면서 주변 9칸 검사
    for (char a : s) {
        if (a == 'I')
            now = { now.first + dx[0], now.second + dy[0] };
        else if (a == 'S')
            now = { now.first + dx[1], now.second + dy[1] };
        else if (a == 'Z')
            now = { now.first + dx[2], now.second + dy[2] };
        else if (a == 'J')
            now = { now.first + dx[3], now.second + dy[3] };

        for (int i = 0; i < 9; i++) {
            pair<int, int> next = { now.first + rx[i], now.second + ry[i] };
            if (spyMap.find(next) != spyMap.end()) {
                for (int spy : spyMap[next]) {
                    heardSpies.insert(spy);
                }
            }
        }
    }

    if (heardSpies.empty())
        cout << -1 << '\n';
    else {
        for (int spy : heardSpies)
            cout << spy << '\n';
    }

    return 0;
}
