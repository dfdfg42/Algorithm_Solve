#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <cstring>

using namespace std;

int visited[100'002];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    if (n == k) {
        cout << 0 << '\n';
        cout << n << '\n';
        return 0;
    }

    queue<int> q;
    memset(visited, -1, sizeof(visited));
    q.push(n);

    while (!q.empty()) {

        int now = q.front();
        q.pop();

        if (now == k) {
            vector<int> ans;
            ans.push_back(k);
            int path = visited[k];

            while (path != n) {
                ans.push_back(path);
                path = visited[path];
            }
            ans.push_back(n);

            cout << ans.size() - 1 << '\n';

            for(int i = ans.size()-1; i>=0; i--)  cout << ans[i] << ' ';
     
            return 0;
        }


        int next = now + 1;
        if (next >= 0 && next <= 100'001) {
            if (visited[next] == -1) {
                q.push(next);
                visited[next] = now;
            }
        }

        next = now * 2;
        if (next >= 0 && next <= 100'001) {
            if (visited[next] == -1) {
                q.push(next);
                visited[next] = now;
            }
        }

        next = now - 1;
        if (next >= 0 && next <= 100'001) {
            if (visited[next] == -1) {
                q.push(next);
                visited[next] = now;
            }
        }

    }
    

    return 0;
}