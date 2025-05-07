#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <algorithm>
#include <string>
#include <iomanip> 
#include <queue>
using namespace std;

vector<bool> visited;
vector<vector<int>> graph;
int gCount;

void dfs(int level, int node) {

    bool isLast = true;

    for (auto a : graph[node]) {
        if (!visited[a]) {
            visited[a] = true;
            dfs(level + 1, a);
            isLast = false;
        }
    }

    if (isLast) {
        gCount += level;
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //각 리프노드에서 루트노드까지의 거리가 짝수면 성헌이가 지고 홀수면 이긴다.

    int n;
    cin >> n;


    visited.resize(n + 1, false);
    graph.resize(n + 1);
    gCount = 0;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    visited[1] = true;
    dfs(0, 1);
    //cout << gCount << '\n';
    if (gCount % 2 == 1)
        cout << "Yes\n";
    else
        cout << "No\n";
}
