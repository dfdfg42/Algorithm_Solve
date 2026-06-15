#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int g_n;
int g_distSize;
int g_weakSize;
int g_origWeakSize;

vector<int> g_dist;
vector<int> g_weak;

int answer;

void dfs(int startIdx, int weakIdx, int distIdx, int usePeople) {

    // 모든 약점을 커버한 경우
    if (weakIdx >= startIdx + g_origWeakSize) {
        answer = min(answer, usePeople);
        return;
    }

    // 사용할 dist가 없는 경우
    if (distIdx >= g_distSize) return;

    // 현재 친구로 커버 가능한 마지막 weak 찾기
    int nextWeakIdx = weakIdx;

    while (nextWeakIdx < g_weakSize &&
           g_weak[nextWeakIdx] <= g_weak[weakIdx] + g_dist[distIdx]) {
        nextWeakIdx++;
    }

    // 현재 친구 사용
    dfs(startIdx, nextWeakIdx, distIdx + 1, usePeople + 1);

    // 현재 친구 스킵
    dfs(startIdx, weakIdx, distIdx + 1, usePeople);
}

int solution(int n, vector<int> weak, vector<int> dist) {

    answer = 987654321;

    g_origWeakSize = weak.size();

    // 원형 -> 일자
    int temp = weak.size();

    for (int i = 0; i < temp; i++) {
        weak.push_back(weak[i] + n);
    }

    g_weak = weak;
    g_weakSize = weak.size();

    // 모든 친구 순열 탐색
    sort(dist.begin(), dist.end());

    do {

        g_dist = dist;
        g_distSize = dist.size();

        for (int i = 0; i < g_origWeakSize; i++) {
            dfs(i, i, 0, 0);
        }

    } while (next_permutation(dist.begin(), dist.end()));

    return (answer == 987654321) ? -1 : answer;
}