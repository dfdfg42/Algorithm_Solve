#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int solution(string s) {
    int answer = 0;
    int n = s.length();

    for (int i = 0; i < n; i++) {

        int idx = 0;
        while (i - idx >= 0 && i + idx < n) {
            if (s[i - idx] != s[i + idx]) break;
            answer = max(answer, 2 * idx + 1);
            idx++;
        }


        idx = 0;
        while (i - idx >= 0 && i + 1 + idx < n) {
            if (s[i - idx] != s[i + 1 + idx]) break;
            answer = max(answer, 2 * idx + 2);
            idx++;
        }
    }

    return answer;
}