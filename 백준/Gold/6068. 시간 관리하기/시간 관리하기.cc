#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 일의 개수, 일의 소요 시간과 마감 시간
int N, workTime, deadline;

// 작업을 저장할 벡터
vector<pair<int, int>> tasks;

// 작업의 마감 시간을 기준으로 오름차순 정렬하기 위한 비교 함수
bool compareByDeadline(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {
    int minDiff = 99999999; // 가능한 가장 늦은 시작 시간을 저장할 변수
    int currentTime = 0; // 현재 시간을 나타내는 변수

    // 작업의 개수를 입력 받음
    cin >> N;
    
    // 각 작업의 소요 시간과 마감 시간을 입력 받아 벡터에 저장
    for (int i = 0; i < N; i++) {
        cin >> workTime >> deadline;
        tasks.push_back(make_pair(workTime, deadline));
    }
    
    // 작업을 마감 시간 기준으로 오름차순 정렬
    sort(tasks.begin(), tasks.end(), compareByDeadline);
    
    // 각 작업을 순서대로 처리
    for (int i = 0; i < N; i++) {
        workTime = tasks[i].first;
        deadline = tasks[i].second;
        
        // 현재 시간에 작업의 소요 시간을 더함
        currentTime += workTime;
        
        // 작업이 마감 시간보다 늦게 끝나면 그 차이를 계산하여 최소 차이를 업데이트
        minDiff = min(minDiff, deadline - currentTime);
    }
    
    // 만약 최소 차이가 0보다 작으면 제 시간에 모든 작업을 끝낼 수 없음을 의미
    if (minDiff < 0) {
        cout << -1;
    } else {
        cout << minDiff;
    }
    
    return 0;
}
