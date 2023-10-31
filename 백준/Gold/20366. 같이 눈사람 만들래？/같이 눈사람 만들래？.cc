#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> snowballs(n);
    for (int i = 0; i < n; i++) {
        cin >> snowballs[i];
    }

    // 눈덩이를 정렬
    sort(snowballs.begin(), snowballs.end());

    // 가능한 모든 눈사람의 조합의 키를 계산
    vector<pair<int, pair<int, int>>> pairs;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            pairs.push_back({ snowballs[i] + snowballs[j], {i, j} });
        }
    }
    sort(pairs.begin(), pairs.end());

    int min_diff = 9876543211;
    for (int i = 0; i < pairs.size() - 1; i++) {
        if (pairs[i].second.first != pairs[i + 1].second.first &&
            pairs[i].second.second != pairs[i + 1].second.second &&
            pairs[i].second.second != pairs[i + 1].second.first &&
            pairs[i].second.first != pairs[i + 1].second.second) {
            int diff = pairs[i + 1].first - pairs[i].first;
            min_diff = min(min_diff, diff);
        }
    }

    cout << min_diff << endl;
    return 0;
}