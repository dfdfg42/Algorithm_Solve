#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<string, int> exts;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        stringstream ss(s);
        string token;
        // '.' 전까지 읽어들이고 무시
        getline(ss, token, '.');
        // '.' 이후에 오는 확장자를 token에 저장
        getline(ss, token);

        exts[token]++;
    }

    // map은 기본적으로 키가 정렬되어 있으므로 정렬은 필요 없지만,
    // sort() 함수를 사용하고 싶다면 vector에 옮긴 후 정렬할 수 있습니다.
    vector<pair<string, int>> extVec(exts.begin(), exts.end());
    sort(extVec.begin(), extVec.end()); // pair의 기본 정렬은 first(확장자) 기준입니다.

    for (const auto& p : exts) {
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}
