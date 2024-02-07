#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> vec(N);
    for (int i = 0; i < N; i++) {
        cin >> vec[i];
    }

    int aC, bC, cC, dC; // 각 연산자의 개수
    cin >> aC >> bC >> cC >> dC;

    vector<int> ops; // 연산자를 숫자로 표현 (더하기: 0, 빼기: 1, 곱하기: 2, 나누기: 3)
    ops.insert(ops.end(), aC, 0);
    ops.insert(ops.end(), bC, 1);
    ops.insert(ops.end(), cC, 2);
    ops.insert(ops.end(), dC, 3);

    int minR = INT_MAX;
    int maxR = INT_MIN;

    do {
        int temp = vec[0];
        for (int i = 1; i < N; i++) {
            switch (ops[i-1]) {
                case 0: // 더하기
                    temp += vec[i];
                    break;
                case 1: // 빼기
                    temp -= vec[i];
                    break;
                case 2: // 곱하기
                    temp *= vec[i];
                    break;
                case 3: // 나누기
                    temp /= vec[i];
                    break;
            }
        }
        minR = min(minR, temp);
        maxR = max(maxR, temp);
    } while (next_permutation(ops.begin(), ops.end()));

    cout << maxR << "\n" << minR << endl;

    return 0;
}
