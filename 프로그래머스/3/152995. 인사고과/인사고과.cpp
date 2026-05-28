#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int solution(vector<vector<int>> scores) {
    int wanhoA = scores[0][0];
    int wanhoB = scores[0][1];
    int wanhoSum = wanhoA + wanhoB;

    sort(scores.begin(), scores.end(), [](auto &x, auto &y) {
        if (x[0] == y[0]) return x[1] < y[1];
        return x[0] > y[0];
    });

    int maxB = -1;
    int rank = 1;

    for (auto &s : scores) {
        int a = s[0];
        int b = s[1];

        if (b < maxB) {
            if(s[0] == wanhoA && s[1] == wanhoB){
                return -1;
            }
            // 이 사람은 인센티브 제외
            // 만약 완호라면 -1
        } else {
            if(wanhoSum < s[0]+s[1]){
                rank++;
            }
            // 인센티브 대상자
            // 완호보다 합산 점수가 크면 rank++
            maxB = max(maxB, b);
        }
    }

    return rank;
}