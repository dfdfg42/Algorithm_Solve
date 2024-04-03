#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <iomanip>
#include <tuple>
#include <sstream>
#include <map>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

bool visited[10];
int result;
vector<pair<int, int>> clients;
pair<int, int> company;
pair<int, int> house;

void dfs(int idx, int dist , pair<int,int> now ) {
    if (idx == clients.size()) {
        dist += abs(now.first - house.first) + abs(now.second - house.second);
        if (dist < result) {
            result = dist;
        }
    }


    for (int i = 0; i < clients.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            dfs(idx +1, dist + (abs(now.first - clients[i].first) + abs(now.second - clients[i].second)), clients[i]);
            visited[i] = false;
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;

    for (int i = 0; i < tc; i++) {
        int n;
        cin >> n;

        cin >> company.first >> company.second;
        cin >> house.first >> house.second;

        clients.resize(n);
        for (int j = 0; j < n; j++) {
            cin >> clients[j].first >> clients[j].second;
        }

        memset(visited, false, sizeof(visited));
        result = INT_MAX;
        dfs(0, 0, company);

        cout << '#' << i+1 << ' ' << result << '\n';
        
    }
        
    return 0;
}
