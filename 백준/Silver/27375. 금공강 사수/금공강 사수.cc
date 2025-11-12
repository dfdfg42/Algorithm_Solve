#include <iostream>
#include <cmath>
#include <tuple>
#include <vector>
#include <map>

using namespace std;

vector<tuple<int, int, int>> lecture;
map<int, pair<int, int>> sub;

int n, k, ans;

void dfs(int point, vector<bool> visited, vector<vector<bool>> schedule, int index) {

    if (point == k) {
        ans++;
        return;
    } else if (point > k) {
        return;
    }

    if (index == n) return;


    for (int i = index; i < n; i++) {
        if (!visited[i] && get<0>(lecture[i]) != 5) {
            int day = get<0>(lecture[i]);
            int end = get<2>(lecture[i]);
            int start = get<1>(lecture[i]);

            bool ok = true;
            for (int t = start; t <= end; t++) {
                if (schedule[day][t]) {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;

            visited[i] = true;

            for (int t = start; t <= end; t++) {
                schedule[day][t] = true;
            }

            dfs(point + (end - start + 1), visited, schedule, i + 1);

            for (int t = start; t <= end; t++) {
                schedule[day][t] = false;
            }

            visited[i] = false;
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        lecture.push_back({ a, b, c });
    }

    ans = 0;
    vector<bool> visited(n, false);
    vector<vector<bool>> schedule(6, vector<bool>(11, false));
    dfs(0, visited, schedule, 0);

    cout << ans << '\n';

    return 0;
}
