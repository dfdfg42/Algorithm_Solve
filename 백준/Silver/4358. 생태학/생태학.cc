#include <iostream>
#include <map>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    map<string, int> trees;
    int total = 0;
    string tree;

    // 입력 받기 (EOF까지)
    while (getline(cin, tree)) {
        trees[tree]++;
        total++;
    }

    // 출력 (사전 순으로 자동 정렬됨)
    cout << fixed << setprecision(4);
    for (auto& entry : trees) {
        double percentage = (entry.second * 100.0) / total;
        cout << entry.first << " " << percentage << '\n';
    }

    return 0;
}
