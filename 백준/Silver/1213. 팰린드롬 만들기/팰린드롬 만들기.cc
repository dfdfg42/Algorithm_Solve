#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int alpha[26];

int main() {
    string s;
    cin >> s;
    int odd = 0;
    char oddChar;

    // 알파벳 개수 세기
    for (char c : s) {
        alpha[c - 'A']++;
    }

    // 홀수 개수 세기
    for (int i = 0; i < 26; i++) {
        if (alpha[i] % 2 != 0) {
            odd++;
            oddChar = i + 'A';
        }
    }

    // 홀수 개수가 1개 이상일 경우 팰린드롬을 만들 수 없음
    if (odd > 1) {
        cout << "I'm Sorry Hansoo" << endl;
        return 0;
    }

    string firstHalf = "";
    string secondHalf = "";

    // 팰린드롬의 첫 번째 절반 생성
    for (int i = 0; i < 26; i++) {
        firstHalf += string(alpha[i] / 2, i + 'A');
    }

    secondHalf = firstHalf;
    reverse(secondHalf.begin(), secondHalf.end());

    // 팰린드롬 만들기
    if (odd == 1) {
        firstHalf += oddChar;
    }

    cout << firstHalf + secondHalf << endl;

    return 0;
}
