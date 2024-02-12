#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 나무들의 높이를 기준으로 자른 후 얻을 수 있는 나무의 총 길이를 계산하는 함수
long long cutTrees(const vector<int>& trees, int height) {
    long long total = 0;
    for (int tree : trees) {
        if (tree > height) {
            total += (tree - height);
        }
    }
    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> trees(N);
    for (int i = 0; i < N; i++) {
        cin >> trees[i];
    }

    int left = 0;
    int right = *max_element(trees.begin(), trees.end()); // 나무들 중 가장 높은 나무의 높이를 right로 설정
    int answer = 0;

    while (left <= right) {
        int mid = (left + right) / 2; // 절단기의 높이를 중간값으로 설정
        long long total = cutTrees(trees, mid); // 현재 절단기 높이에서 얻을 수 있는 나무의 총 길이

        if (total < M) { // 목표한 나무 길이에 도달하지 못한 경우
            right = mid - 1;
        } else { // 목표한 나무 길이 이상을 얻은 경우
            answer = mid; // 가능한 답을 갱신
            left = mid + 1; // 더 높은 높이에서도 확인
        }
    }

    cout << answer << '\n';

    return 0;
}
