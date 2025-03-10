#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ans = -1;

// config: 현재 육각형으로 배치된 6개의 삼각형, 
// 각 삼각형은 [left, outer, right] 순서로 저장됨.
void checkConfiguration(const vector<vector<int>>& config) {
    int sum = 0;
    for (int i = 0; i < 6; i++) {
        int prev = (i + 5) % 6;  // 이전 삼각형 (i==0일 때는 5번)
        int next = (i + 1) % 6;  // 다음 삼각형
        // 조건: 현재 삼각형의 왼쪽은 이전 삼각형의 오른쪽과,
        //       현재 삼각형의 오른쪽은 다음 삼각형의 왼쪽과 일치해야 함.
        if (config[i][0] != config[prev][2] || config[i][2] != config[next][0])
            return;
        sum += config[i][1];
    }
    ans = max(ans, sum);
}

// dfsRotation: 현재 순열에 따른 삼각형 집합(perm)에서 idx번째 삼각형의 회전 상태를 결정하는 재귀 함수
// config: 현재까지 회전한 결과를 저장하는 배열 (길이 6)
// perm: 순열에 따른 삼각형 순서 (각 삼각형은 회전 전 상태)
void dfsRotation(int idx, vector<vector<int>>& config, const vector<vector<int>>& perm) {
    if (idx == 6) {
        checkConfiguration(config);
        return;
    }
    // perm[idx]에 해당하는 삼각형에 대해 3가지 회전 시도
    vector<int> tri = perm[idx];
    for (int r = 0; r < 3; r++) {
        config[idx] = tri;  // 현재 회전 상태 저장
        dfsRotation(idx + 1, config, perm);
        // 삼각형 회전: cyclic하게 왼쪽 회전 ( {A, B, C} -> {B, C, A} )
        rotate(tri.begin(), tri.begin() + 1, tri.end());
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        // 한 세트당 6개의 삼각형 입력
        vector<vector<int>> triangles(6, vector<int>(3));
        for (int i = 0; i < 6; i++) {
            if (!(cin >> triangles[i][0] >> triangles[i][1] >> triangles[i][2])) {
                return 0; // 입력이 없으면 종료
            }
        }

        char delim;
        cin >> delim;  // 세트 구분자: '*' 또는 마지막 세트 '$'

        ans = -1;  // 최대 점수를 -1로 초기화 ("none" 상태)

        // 6개의 삼각형 순서를 전수 탐색하기 위해 순열 사용
        vector<int> idx = { 0,1,2,3,4,5 };
        do {
            // 현재 순열에 따른 삼각형 순서를 perm에 저장
            vector<vector<int>> perm(6, vector<int>(3));
            for (int i = 0; i < 6; i++) {
                perm[i] = triangles[idx[i]];
            }
            vector<vector<int>> config(6, vector<int>(3));  // 각 삼각형의 회전 상태 저장
            dfsRotation(0, config, perm);
        } while (next_permutation(idx.begin(), idx.end()));

        if (ans == -1)
            cout << "none" << "\n";
        else
            cout << ans << "\n";

        if (delim == '$')
            break;
    }

    return 0;
}
