#include <iostream>
#include <vector>
using namespace std;


vector<vector<int>> nodes;
vector<bool> visited;
vector<bool> dfsVis;

void checkAns(vector<int> &vec) {

    for (auto a : vec) {
        visited[a] = true;
    }

}

void dfs(int input ,int first,vector<int> &vec) {

    dfsVis[input] = true;
    
    if (nodes[input].back() == first) {
        checkAns(vec);

    }
    else if(!dfsVis[nodes[input].back()]) {
        vec.push_back(nodes[input].back());
        dfs(nodes[input].back(), first, vec);

    }

    return;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    nodes.resize(n+1);
    visited.resize(n + 1, false);

    for (int i = 1; i <= n; i++) {

        int input;
        cin >> input;
        nodes[i].push_back(input);

    }

    for (int i = 1; i <= n; i++) {


        if (!visited[i]) {
            vector<int> temp;
            dfsVis.assign(n + 1, false);
            temp.push_back(i);
            dfs(i, i, temp);
        }

    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) if (visited[i]) cnt++;
    cout << cnt << '\n';
    for (int i = 1; i <= n; i++) {
        if (visited[i]) cout << i << '\n';
    }

    return 0;
}
