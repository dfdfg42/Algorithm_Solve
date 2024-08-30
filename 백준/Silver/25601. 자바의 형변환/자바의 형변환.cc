#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <climits>

using namespace std;

map<string, vector<string>> node;
map<string, bool> dfsCheck;
int result;

void dfs(string start, string target) {

    if (start == target) {
        result = 1;
        return;
    }



    for (auto a : node[start]) {
        if (!dfsCheck[a]) {
            dfsCheck[start] = true;
            dfs(a, target);
            dfsCheck[start] = false;
        }
    }

    
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        string s1, s2;
        cin >> s1 >> s2;

        dfsCheck[s1] = false;
        dfsCheck[s2] = false;

        node[s1].push_back(s2);
    }

    string a1, a2;
    cin >> a1 >> a2;
    result = 0;

    dfs(a1, a2);
    dfs(a2, a1);
    
    cout << result << '\n';

    return 0;
}
