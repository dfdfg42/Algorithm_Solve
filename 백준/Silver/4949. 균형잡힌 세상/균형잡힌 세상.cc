#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>
#include <string>
using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<string> lines;
    vector<bool> answers;

    while (true) {
        string input;
        getline(cin, input);

        if (input == ".") {
            break;
        }

        vector<char> brackets;
        bool flag = true;

        for (int i = 0; i < input.size(); i++) {

            if (input[i] == '(') {
                brackets.push_back('(');
            }
            else if (input[i] == ')') {
                if (brackets.empty()) {
                    flag = false;
                    break;
                }
                else if (brackets.back() == '(') {
                    brackets.pop_back();
                }
                else if (brackets.back() != '(') {
                    flag = false;
                    break;
                }
            }
            else if (input[i] == '[') {
                brackets.push_back('[');
            }
            else if (input[i] == ']') {
                if (brackets.empty()) {
                    flag = false;
                    break;
                }
                else if (brackets.back() == '[') {
                    brackets.pop_back();
                }
                else if (brackets.back() != '[') {
                    flag = false;
                    break;
                }
            }

        }
        
        if (!brackets.empty()) {
            flag = false;
        }

        if (flag) {
            answers.push_back(true);
        }
        else {
            answers.push_back(false);
        }
    }

    for (bool a : answers) {
        if (a == true) {
            cout << "yes" << '\n';
        }
        else {
            cout << "no" << '\n';
        }
    }


    return 0;
}
