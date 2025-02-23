#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;

    vector<string> aVec, bVec;
    string token;

    // Source 경로 분할
    stringstream ss(a);
    while (getline(ss, token, '/')) {
        aVec.push_back(token);
    }

    // Destination 경로 분할
    stringstream ss2(b);
    while (getline(ss2, token, '/')) {
        bVec.push_back(token);
    }

    int aSize = aVec.size();
    int bSize = bVec.size();

    // 공통 prefix 찾기
    int prefix = 0;
    while (prefix < aSize && prefix < bSize && aVec[prefix] == bVec[prefix]) {
        prefix++;
    }

    // 공통 suffix 찾기
    int suffix = 0;
    while (suffix < aSize - prefix && suffix < bSize - prefix &&
           aVec[aSize - 1 - suffix] == bVec[bSize - 1 - suffix]) {
        suffix++;
    }

    // 출력 시작 (공통 prefix)
    for (int i = 0; i < prefix; i++) {
        cout << aVec[i] << '/';
    }

    // 변경된 부분 (B => C)
    cout << '{';
    for (int i = prefix; i < aSize - suffix; i++) {
        cout << aVec[i];
        if (i < aSize - suffix - 1) cout << '/';
    }
    cout << " => ";
    for (int i = prefix; i < bSize - suffix; i++) {
        cout << bVec[i];
        if (i < bSize - suffix - 1) cout << '/';
    }
    cout << '}';

    // 공통 suffix 출력
    for (int i = aSize - suffix; i < aSize; i++) {
        cout << '/' << aVec[i];
    }
    cout << '\n';

    return 0;
}
