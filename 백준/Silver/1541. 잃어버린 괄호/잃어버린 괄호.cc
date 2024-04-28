#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string input;
    cin >> input;

    // 이 변수는 현재 숫자를 읽기 위해 사용됩니다.
    int currentNumber = 0;
    // 이 변수는 전체 결과를 저장합니다.
    int result = 0;
    // 이 변수는 현재 숫자를 더할지 뺄지를 결정합니다.
    bool subtract = false;

    // '+' 또는 '-'를 만날 때마다 숫자를 종합해서 처리합니다.
    for (int i = 0; i <= input.length(); ++i) {
        if (i == input.length() || input[i] == '+' || input[i] == '-') {
            // 첫번째 '-' 이후부터는 모든 숫자를 빼야 합니다.
            if (subtract) {
                result -= currentNumber;
            }
            else {
                result += currentNumber;
            }
            currentNumber = 0;
            // '-' 기호를 만나면 이후 숫자는 빼야 함을 표시합니다.
            if (i != input.length() && input[i] == '-') {
                subtract = true;
            }
        }
        else {
            // 숫자를 읽습니다. (연속된 숫자를 처리하기 위해 10을 곱함)
            currentNumber = currentNumber * 10 + (input[i] - '0');
        }
    }

    // 최종 결과를 출력합니다.
    cout << result << endl;

    return 0;
}
