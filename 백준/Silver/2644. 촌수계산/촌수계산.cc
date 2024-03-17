#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

bool check[103];

int dfs(int node, vector<vector<int>>& families, int depth, int target) {
    if (node == target) { 
        return depth;
    }
    check[node] = true; 

    int result = INT_MAX; 
    for (int i = 0; i < families[node].size(); i++) {
        int next = families[node][i];
        if (!check[next]) { 
            int curResult = dfs(next, families, depth + 1, target);
            if (curResult != -1) { 
                result = min(result, curResult); 
            }
        }
    }

    return result == INT_MAX ? -1 : result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int start, target;
    cin >> start >> target;

    vector<vector<int>> families(N+1); // 인덱스를 1부터 사용하기 위해 N+1 크기로 초기화

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;

        families[x].push_back(y);
        families[y].push_back(x);
    }
    
    fill_n(check, 103, false); // check 배열 초기화
    int result = dfs(start, families, 0, target); // 깊이를 0부터 시작

    cout << result << '\n';
   
    return 0;
}
