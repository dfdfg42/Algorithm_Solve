#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, C;
    cin >> N >> C;

    vector<int> houses(N);
    for (int i = 0; i < N; ++i) {
        cin >> houses[i];
    }
    
    // 집의 좌표를 정렬
    sort(houses.begin(), houses.end());
    
    int left = 1; // 최소 거리
    int right = houses[N - 1] - houses[0]; // 최대 거리
    int result = 0;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        int installed = 1; // 첫 번째 집에 공유기 설치
        int lastInstalled = houses[0]; // 마지막으로 공유기를 설치한 집의 위치
        
        for (int i = 1; i < N; ++i) {
            if (houses[i] - lastInstalled >= mid) { // 설치 조건 검사
                installed++;
                lastInstalled = houses[i];
            }
        }
        
        if (installed >= C) { // C개 이상 설치 가능하면 거리를 늘림
            left = mid + 1;
            result = mid; // 현재 mid 값 저장
        } else { // C개 미만이면 거리를 줄임
            right = mid - 1;
        }
    }
    
    cout << result << endl; // 최적의 거리 출력
    
    return 0;
}
