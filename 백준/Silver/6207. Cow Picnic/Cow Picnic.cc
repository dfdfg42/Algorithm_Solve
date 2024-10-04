#include <iostream>
#include <vector>

using namespace std;

int k, n, m;
vector<vector<int>> graph;
vector<int> cowPos;
vector<vector<bool>> check;

void dfs(int cowNum, int index) {
    for (auto a : graph[index]) {
        if (!check[cowNum][a]) {
            check[cowNum][a] = true;
            dfs(cowNum, a);
        }
    }
}

int main() {
    cin >> k >> n >> m;
    check.resize(k, vector<bool>(n, false));

    for (int i = 0; i < k; i++) {
        int input;
        cin >> input;
        cowPos.push_back(input - 1);
    }

    graph.resize(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
    }

    for (int i = 0; i < k; i++) {
        int cp = cowPos[i];
        check[i][cp] = true;
        dfs(i, cp);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        bool all_cows_can_reach = true;
        for (int j = 0; j < k; j++) {
            if (!check[j][i]) {
                all_cows_can_reach = false;
                break;
            }
        }
        if (all_cows_can_reach) ans++;
    }

    cout << ans << endl;

    return 0;
}
