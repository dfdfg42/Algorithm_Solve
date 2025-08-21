#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n; 
    string s;
    cin >> s;

    int len = s.length();
    vector<int> t(len + 1, 0);
    vector<int> g(len + 1, 0);
    vector<int> f(len + 1, 0);
    vector<int> p(len + 1, 0);

    for (int i = 0; i < len; i++) {
        t[i + 1] = t[i];
        g[i + 1] = g[i];
        f[i + 1] = f[i];
        p[i + 1] = p[i];
        if (s[i] == 'T') t[i + 1]++;
        else if (s[i] == 'G') g[i + 1]++;
        else if (s[i] == 'F') f[i + 1]++;
        else if (s[i] == 'P') p[i + 1]++;
    }

    map<vector<int>, long long> counts;
    long long answer = 0;


    counts[{0, 0, 0, 0}] = 1;

    for (int i = 1; i <= len; i++) {
        vector<int> currentState = { t[i] % 3, g[i] % 3, f[i] % 3, p[i] % 3 };


        answer += counts[currentState];

        counts[currentState]++;
    }

    cout << answer << "\n";

    return 0;
}