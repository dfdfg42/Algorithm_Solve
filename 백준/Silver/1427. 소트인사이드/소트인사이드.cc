#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    string s;
    cin >> s;

    vector<int> vec;
    for (int i = 0; i < s.length(); i++) {
        vec.push_back(s[i] - '0');
    }

    sort(vec.begin(), vec.end(),greater<int>());

    for (int v : vec) {
        cout << v;
    }
}
