#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int st = 0, en = 0;
    int maxLength = 0;
    int curType = 0;

    int alpha[26] = { 0, };

    while (en < s.length()) {
        if (alpha[s[en] - 'a']++ == 0) curType++; // 새로운 알파벳 타입을 발견


        while (curType > n) { // 허용된 타입을 초과하면 앞에서부터 제거
            if (--alpha[s[st] - 'a'] == 0) curType--;
            st++;
        }

        maxLength = max(maxLength, en - st + 1); // 최대 길이 갱신
        en++;
    }

    cout << maxLength << endl;

    return 0;
}
