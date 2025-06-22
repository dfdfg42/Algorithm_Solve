#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

long long fact[21];

void precompute_factorials() {
    fact[0] = 1;
    for (int i = 1; i <= 20; ++i) {
        fact[i] = fact[i - 1] * i;
    }
}

void solve_problem_1(int n) {
    long long k;
    cin >> k;

    vector<int> numbers;
    for (int i = 1; i <= n; ++i) {
        numbers.push_back(i);
    }

    vector<int> result;

    k--;

    for (int i = n; i > 0; --i) {
        long long f = fact[i - 1];
        int index = k / f;
        k %= f;

        result.push_back(numbers[index]);
        numbers.erase(numbers.begin() + index);
    }

    for (int i = 0; i < n; ++i) {
        cout << result[i] << " ";
    }
    cout << "\n";
}

void solve_problem_2(int n) {
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    vector<int> numbers;
    for (int i = 1; i <= n; ++i) {
        numbers.push_back(i);
    }

    long long rank = 0;

    for (int i = 0; i < n; ++i) {
        int current_num = p[i];

        int index = -1;
        for (int j = 0; j < numbers.size(); ++j) {
            if (numbers[j] == current_num) {
                index = j;
                break;
            }
        }

        long long f = fact[n - 1 - i];
        rank += (long long)index * f;

        numbers.erase(numbers.begin() + index);
    }

    cout << rank + 1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute_factorials();

    int n, problem_type;
    cin >> n >> problem_type;

    if (problem_type == 1) {
        solve_problem_1(n);
    }
    else {
        solve_problem_2(n);
    }

    return 0;
}