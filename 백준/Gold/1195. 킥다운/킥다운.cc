#include <iostream>
#include <string>
#include <climits>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    int shortLen;
    bool isashort = false;
    if (a.length() > b.length()) {
        shortLen = b.length();
    }
    else {
        shortLen = a.length();
        isashort = true; // 수정된 부분
    }

    string extraString(shortLen, '0'); // extraString 생성 간소화

    int minLen = INT_MAX;

    if (!isashort) { // a가 더 길거나 같은 경우
        string checkString = extraString + a + extraString;

        for (int i = 0; i <= checkString.length() - b.length(); i++) {
            bool isPossible = true;
            for (int j = 0; j < b.length(); j++) {
                int sum = (checkString[i + j] - '0') + (b[j] - '0');
                if (sum == 4) { // 이와 이가 만나면 불가능함
                    isPossible = false;
                    break;
                }
            }
            if (isPossible) {
                int left = i - shortLen;
                int right = left + b.length();
                int totalLen = max((int)a.length(), right) - min(0, left);
                minLen = min(minLen, totalLen);
            }
        }
    }
    else { // b가 더 길거나 같은 경우
        string checkString = extraString + b + extraString;

        for (int i = 0; i <= checkString.length() - a.length(); i++) {
            bool isPossible = true;
            for (int j = 0; j < a.length(); j++) {
                int sum = (checkString[i + j] - '0') + (a[j] - '0');
                if (sum == 4) { // 이와 이가 만나면 불가능함
                    isPossible = false;
                    break;
                }
            }
            if (isPossible) {
                int left = i - shortLen;
                int right = left + a.length();
                int totalLen = max((int)b.length(), right) - min(0, left);
                minLen = min(minLen, totalLen);
            }
        }
    }

    cout << minLen << '\n';

    return 0;
}
