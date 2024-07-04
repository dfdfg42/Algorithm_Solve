#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

long long calculate(long long a, long long b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    return 0;
}

long long evaluate_expression(vector<long long> numbers, vector<char> operators, vector<char> precedence) {
    for (char op : precedence) {
        for (int i = 0; i < operators.size(); ++i) {
            if (operators[i] == op) {
                numbers[i] = calculate(numbers[i], numbers[i + 1], op);
                numbers.erase(numbers.begin() + i + 1);
                operators.erase(operators.begin() + i);
                --i;
            }
        }
    }
    return numbers[0];
}

long long solution(string expression) {
    vector<long long> numbers;
    vector<char> operators;
    string num = "";
    
    for (char c : expression) {
        if (isdigit(c)) {
            num += c;
        } else {
            numbers.push_back(stoll(num));
            num = "";
            operators.push_back(c);
        }
    }
    numbers.push_back(stoll(num));

    vector<vector<char>> precedence_permutations = {
        {'+', '-', '*'}, {'+', '*', '-'},
        {'-', '+', '*'}, {'-', '*', '+'},
        {'*', '+', '-'}, {'*', '-', '+'}
    };

    long long max_value = 0;
    for (auto precedence : precedence_permutations) {
        long long result = evaluate_expression(numbers, operators, precedence);
        if (result < 0) result = -result;
        if (result > max_value) max_value = result;
    }

    return max_value;
}
