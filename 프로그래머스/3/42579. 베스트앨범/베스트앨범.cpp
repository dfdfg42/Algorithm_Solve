#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool valueComp(const pair<string, int>& a, const pair<string, int>& b) {
    return a.second > b.second; // 장르별 총 재생 수에 따라 내림차순 정렬
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    map<string, int> genreMap;

    // 장르별 총 재생 수를 계산
    for (int i = 0; i < genres.size(); i++) {
        genreMap[genres[i]] += plays[i];
    }

    // 장르별 총 재생 수를 벡터로 이동
    vector<pair<string, int>> vec(genreMap.begin(), genreMap.end());

    // 벡터를 재생 수에 따라 정렬
    sort(vec.begin(), vec.end(), valueComp);

    vector<int> answer;
    for (int i = 0; i < vec.size(); i++) {
        pair<int, int> first = {-1, -1}; // 최대 재생수, 인덱스
        pair<int, int> second = {-1, -1}; // 두번째로 많은 재생수, 인덱스

        for (int j = 0; j < genres.size(); j++) {
            if (genres[j] == vec[i].first) {
                if (plays[j] > first.first) {
                    second = first; // 기존 첫번째 최대값을 두번째로 밀어냄
                    first = {plays[j], j}; // 새로운 최대값 설정
                } else if (plays[j] > second.first) {
                    second = {plays[j], j}; // 두번째 최대값 갱신
                }
            }
        }
        if (first.second != -1) answer.push_back(first.second);
        if (second.second != -1) answer.push_back(second.second);
    }
    
    return answer;
}
