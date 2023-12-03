#include <string>
#include <vector>
using namespace std;

int cntCompressedStr(int cnt, string s) {
    for (int i=0; i<s.size();) {
        string cmp = s.substr(i, cnt);// 비교 문자열
        int sameCnt = 1;// 비교 문자열과 같은 문자열 개수(비교 문자열 포함)
        for (int j=i+cnt; j<s.size(); j+=cnt) {// 같다면 개수++
            if (cmp == s.substr(j, cnt)) sameCnt++;
            else break;
        }
        if (sameCnt == 1) {
        // 해당 비교문자열이 뒤에 연속으로 반복되지 않는다면 자르는 단위만큼 i값에 cnt를 더한다.
            i += cnt;
            continue;
        }
        cmp = to_string(sameCnt) + cmp;// 비교문자열과 같은 문자열 개수 + 비교문자열 을 한 문자열로 합쳐준다.
        string rest = s.substr(i + cnt * sameCnt);// 나머지 문자열
        s =  s.substr(0, i) + cmp + rest;// 변환한 문자열을 다시 합쳐준다.
        i += cmp.size();//변환한 이후부터로 다시 인덱스 설정
    }
    return s.size();
}

int solution(string s) {
    int answer = s.size();// 압축을 못한다면 원래크기
    for (int i=1; i<=s.size(); i++) {// 1~문자열 크기 만큼으로 압축할때
        answer = min(answer, cntCompressedStr(i, s));
    }
    return answer;
}