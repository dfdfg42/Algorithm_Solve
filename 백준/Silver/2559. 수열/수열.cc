#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> temperatures(N);
    for(int i = 0; i < N; ++i) {
        cin >> temperatures[i];
    }

    // 처음 K일 간의 온도 합 계산
    int current_sum = 0;
    for(int i = 0; i < K; ++i) {
        current_sum += temperatures[i];
    }

    int max_sum = current_sum;

    // 슬라이딩 윈도우를 이용한 연속된 K일 간의 온도 합 최대값 계산
    for(int i = K; i < N; ++i) {
        current_sum += temperatures[i] - temperatures[i-K];
        max_sum = max(max_sum, current_sum);
    }

    // 최대 온도 합 출력
    cout << max_sum << endl;

    return 0;
}
