#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    map<string, string> pass;

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string key, value;
        cin >> key >> value;

        pass[key] = value;
    }

    for (int i = 0; i < M; i++) {
        string findKey;
        cin >> findKey;
        cout << pass[findKey] << '\n';
    }

    return 0;
}
