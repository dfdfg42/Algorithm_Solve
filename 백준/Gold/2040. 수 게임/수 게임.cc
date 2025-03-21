#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 충분히 큰 양의 값과 음의 값 (dp 미계산 여부 표시용)
const int INF = 1000000000;
const int UNCOMPUTED = -1000000000;

int n;  // 게임에 사용될 숫자의 개수

// 재귀함수 memo: 현재 인덱스 cur부터 시작할 때, 
// (A의 합 – B의 합)의 최적 결과(양 플레이어 모두 최선을 다한 경우)를 반환합니다.
// 여기서 배열은 0-indexed로 처리하며, 
// prefix[i+1] - prefix[cur]는 구간 [cur, i]의 합을 의미합니다.
int memo(int cur, const vector<int>& prefix, vector<int>& dp) {
    if (cur == n) return 0;  // 기저 조건: 남은 숫자가 없으면 결과 0
    if (dp[cur] != UNCOMPUTED) return dp[cur];  // 이미 계산한 경우 바로 반환

    int best = INF;  // 가능한 결과 중 최솟값을 찾습니다.
    // 현재 인덱스 cur부터 끝까지 (즉, arr[cur]부터 arr[n-1]) 연속 구간을 선택하는 모든 경우에 대해
    for (int i = cur; i < n; i++) {
        // 구간 [cur, i]의 합을 구합니다.
        int segSum = prefix[i + 1] - prefix[cur];
        // 선택 후, 상대가 최적으로 플레이한 결과는 memo(i + 1)로 표현되므로,
        // 현재 플레이어의 최종 결과는 "내가 얻은 구간의 합 - 상대가 얻을 결과" 입니다.
        best = min(best, segSum - memo(i + 1, prefix, dp));
    }
    
    return dp[cur] = best;
}

void solveTestCase() {
    // 게임에서는 오른쪽 끝에서부터 숫자를 선택하므로,
    // 입력으로 받은 숫자들을 뒤집어서 저장합니다.
    // 즉, 첫 번째 입력값은 배열의 마지막 요소로, 마지막 입력값은 배열의 첫 번째 요소로 저장됩니다.
    vector<int> arr(n);
    for (int i = n - 1; i >= 0; i--) {
        cin >> arr[i];
    }
    
    // 누적합(prefix) 계산: prefix[0] = 0, prefix[i+1] = arr[0] + ... + arr[i]
    vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + arr[i];
    }
    
    // dp 벡터 초기화: dp[cur]는 아직 계산되지 않았음을 표시하기 위해 UNCOMPUTED 값으로 채웁니다.
    vector<int> dp(n + 1, UNCOMPUTED);
    dp[n] = 0;  // 기저 조건: 남은 숫자가 없으면 결과는 0

    // 전체 게임은 인덱스 0부터 시작합니다.
    int result = memo(0, prefix, dp);
    
    // 결과에 따라 승자를 출력합니다.
    // result < 0: A가 이김, result > 0: B가 이김, result == 0: 비김
    if (result < 0) cout << "A\n";
    else if (result > 0) cout << "B\n";
    else cout << "D\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    int testCases = 3;
    while (testCases--) {
        solveTestCase();
    }
    
    return 0;
}
