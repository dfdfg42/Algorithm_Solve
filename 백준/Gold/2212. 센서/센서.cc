#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> sensors(N);

    for (int i = 0; i < N; i++) {
        cin >> sensors[i];
    }

    sort(sensors.begin(), sensors.end());

    vector<int> gaps;
    for (int i = 1; i < N; i++) {
        gaps.push_back(sensors[i] - sensors[i - 1]);
    }

    // 간격들을 내림차순으로 정렬합니다.
    sort(gaps.begin(), gaps.end(), greater<int>());

    // K가 센서의 수보다 크거나 같으면, 모든 센서를 개별 집중국으로 커버할 수 있으므로 0을 출력합니다.
    if (K >= N) {
        cout << 0 << endl;
        return 0;
    }

    // 가장 큰 K-1개의 간격을 제외하고 나머지 간격들의 합을 계산합니다.
    int totalDistance = 0;
    for (int i = K - 1; i < gaps.size(); i++) {
        totalDistance += gaps[i];
    }

    cout << totalDistance << endl;

    return 0;
}
