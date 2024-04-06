#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>
#include <string>
using namespace std;

bool flag;

void dfs(vector<vector<int>> &vec, bool visited[],int idx) {
    if (idx == 99) {
        flag = true;
        return;
    }
    for (int i = 0; i < vec[idx].size(); i++) {
        int nextIdx = vec[idx][i];
        if (!visited[nextIdx]) {
            visited[nextIdx] = true;
            dfs(vec, visited, nextIdx);
            visited[nextIdx] = false;
        }
    }
    return;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int tc = 1; tc <= 10; tc++) {

        int n, length;
        cin >> n >> length;
        vector<vector<int>> nodes(100,vector<int>(0));
        bool visited[100] = { false };

        for (int i = 0; i < length; i++) {

            int a, b;
            cin >> a >> b;
            nodes[a].push_back(b);
        }

        flag = false;

        dfs(nodes, visited, 0);

        cout << '#' << tc << ' ' << (flag ? 1 : 0) << '\n';
    }

    return 0;
}
