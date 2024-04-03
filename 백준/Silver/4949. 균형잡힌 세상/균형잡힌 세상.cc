#include <iostream>
#include <vector>
#include <map>
using namespace std;

// 괄호의 짝을 확인하는 함수
bool isValidBracketSequence(const string& input) {
    vector<char> stack;
    map<char, char> bracketPairs = {{')', '('}, {']', '['}};
    
    for (char ch : input) {
        if (ch == '(' || ch == '[') {
            stack.push_back(ch);
        } else if (ch == ')' || ch == ']') {
            if (stack.empty() || stack.back() != bracketPairs[ch]) {
                return false;
            }
            stack.pop_back();
        }
    }
    return stack.empty();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<bool> answers;
    string input;

    while (true) {
        getline(cin, input);
        if (input == ".") break;

        answers.push_back(isValidBracketSequence(input));
    }

    for (bool isValid : answers) {
        cout << (isValid ? "yes" : "no") << '\n';
    }

    return 0;
}
