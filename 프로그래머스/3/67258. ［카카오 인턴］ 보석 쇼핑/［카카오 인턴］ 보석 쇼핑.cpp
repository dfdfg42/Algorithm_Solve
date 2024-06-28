#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <climits>
#include <set>

using namespace std;

vector<int> solution(vector<string> gems) {
    unordered_map<string, int> gemCount;
    set<string> gemTypes(gems.begin(), gems.end());
    int totalTypes = gemTypes.size();
    
    int minlength = INT_MAX;
    pair<int, int> index;
    
    // 투 포인터, 슬라이딩 윈도우를 활용
    int l = 0, r = 0;
    int currentTypes = 0;
    
    while (true) {
        if (currentTypes == totalTypes) { // 모든 종류의 보석이 포함되었을 때
            if (minlength > r - l) {
                minlength = r - l;
                index = make_pair(l, r);
            }
            if (--gemCount[gems[l]] == 0) {
                currentTypes--;
            }
            l++;
        } else { // 모든 종류의 보석이 포함되지 않았을 때
            if (r == gems.size()) break; // 종료 조건
            if (gemCount[gems[r]]++ == 0) {
                currentTypes++;
            }
            r++;
        }
    }
    
    vector<int> answer = {index.first + 1, index.second};
    return answer;
}
