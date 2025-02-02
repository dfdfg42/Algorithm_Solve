#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector<vector<int>> nodes;
int cost[1001];
int visited[1001];
int sw;
int n;

void dfs(int now, int money) {
    if (sw == 1)
        return;

    // n번째 방 도착
    if (now == n) {
        sw = 1;
        return;
    }

    for (size_t i = 0; i < nodes[now].size(); i++) {
        int next = nodes[now][i];

        if (visited[next] == 1)
            continue;

        // L
        if (cost[next] > 0) {
            if (cost[next] > money)
                money = cost[next];
        }
        // T or E
        else
            money += cost[next];

        //돈 부족해서 못감
        if (money < 0)
            return;

        visited[next] = 1;
        dfs(next, money);
        visited[next] = 0;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    while (true) {
        cin >> n;
        if (n == 0) break;

        nodes.resize(n + 1);
        sw = 0;
        for (int i = 1; i <= n; i++) {
            char type;
            int c;

            cin >> type >> c;
            while (true) {
                int next;
                cin >> next;
                if (next == 0) break;

                nodes[i].push_back(next);
            }

            if (type == 'T') cost[i] = -c;
            else cost[i] = c;
        }

        if (cost[1] >= 0) {
            visited[1] = 1;
            dfs(1, cost[1]);
        }
        
        if (sw == 1) cout << "Yes\n";
        else cout << "No\n";

        nodes.clear();

        memset(cost, 0, sizeof(cost));
        memset(visited, 0, sizeof(visited));
    }

    return 0;
}
