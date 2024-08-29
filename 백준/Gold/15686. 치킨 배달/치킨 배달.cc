#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int n, m;
vector<pair<int, int>> houses;
vector<pair<int, int>> chicken;
vector<vector<int>> dist;  // 각 집과 치킨집 간의 거리

int calcDistance(vector<int> &selected) {
    int totalDist = 0;
    for (int i = 0; i < houses.size(); i++) {
        int minDist = INT_MAX;
        for (int j : selected) {
            minDist = min(minDist, dist[i][j]);
        }
        totalDist += minDist;
    }
    return totalDist;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int value;
            cin >> value;
            if (value == 1) {
                houses.push_back({i, j});
            } else if (value == 2) {
                chicken.push_back({i, j});
            }
        }
    }

    int hSize = houses.size();
    int cSize = chicken.size();

    dist.resize(hSize, vector<int>(cSize));

    // 미리 집과 치킨집 간의 거리를 계산해 둔다.
    for (int i = 0; i < hSize; i++) {
        for (int j = 0; j < cSize; j++) {
            dist[i][j] = abs(houses[i].first - chicken[j].first) + abs(houses[i].second - chicken[j].second);
        }
    }

    vector<int> indices(cSize);
    fill(indices.end() - m, indices.end(), 1);

    int minDist = INT_MAX;

    do {
        vector<int> selected;
        for (int i = 0; i < cSize; i++) {
            if (indices[i]) selected.push_back(i);
        }
        minDist = min(minDist, calcDistance(selected));
    } while (next_permutation(indices.begin(), indices.end()));

    cout << minDist << endl;
    return 0;
}
