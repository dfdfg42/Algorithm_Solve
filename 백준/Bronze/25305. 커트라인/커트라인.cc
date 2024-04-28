#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, k;
    cin >> N >> k;

    vector<int> scores(N);
    for (int i = 0; i < N; i++) {
        cin >> scores[i];
    }

    // 점수를 내림차순으로 정렬
    sort(scores.begin(), scores.end(), greater<int>());

    // 상을 받는 커트라인 출력
    // 내림차순 정렬이므로 k번째는 인덱스 k-1 위치에 있습니다.
    cout << scores[k - 1] << '\n';

    return 0;
}
