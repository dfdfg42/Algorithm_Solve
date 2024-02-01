#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    deque<int> dq;
    for (int i = 1; i <= N; ++i) {
        dq.push_back(i);
    }

    int operations = 0;
    for (int i = 0; i < M; ++i) {
        int target;
        cin >> target;
        
        // 위치 찾기
        int index = find(dq.begin(), dq.end(), target) - dq.begin();
        
        // 왼쪽 이동과 오른쪽 이동 중 최소 이동 결정
        int leftShift = index;
        int rightShift = dq.size() - index;
        
        if (leftShift < rightShift) {
            // 왼쪽으로 회전
            for (int j = 0; j < leftShift; ++j) {
                dq.push_back(dq.front());
                dq.pop_front();
                operations++;
            }
        } else {
            // 오른쪽으로 회전
            for (int j = 0; j < rightShift; ++j) {
                dq.push_front(dq.back());
                dq.pop_back();
                operations++;
            }
        }
        
        // 원소 제거
        dq.pop_front();
    }

    cout << operations;

    return 0;
}
