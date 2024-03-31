#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> lectures(N);
    for (int i = 0; i < N; ++i) {
        cin >> lectures[i].first >> lectures[i].second;
    }

    // 시작 시간에 따라 오름차순으로 정렬
    sort(lectures.begin(), lectures.end());

    // 우선순위 큐는 강의실의 종료 시간을 오름차순으로 관리
    priority_queue<int, vector<int>, greater<int>> pq;

    for (const auto& lecture : lectures) {
        if (!pq.empty() && pq.top() <= lecture.first) {
            // 현재 강의 시작 시간이 가장 먼저 끝나는 강의실의 종료 시간보다 같거나 크면 재사용
            pq.pop();
        }
        pq.push(lecture.second); // 현재 강의실을 추가(종료 시간으로)
    }

    cout << pq.size(); // 사용된 강의실의 수 출력
    return 0;
}
