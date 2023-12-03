#include <iostream>
#include <stack>
#include <string>

using namespace std;

typedef pair<long long, long long> frac;


long long gcd(long long a, long long b) {
    while (b != 0) {
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;
}


int main() {
    int n;
    cin >> n;

    stack<frac> s;

    for (int i = 0; i < n; ++i) {
        string token;
        cin >> token;

        if (token == "(") {
            s.push(make_pair(-1, -1)); // '('를 표시하기 위한 더미 값
        }
        else if (token == ")") {
            frac z = s.top(); s.pop();
            frac y = s.top(); s.pop();
            frac x = s.top(); s.pop();
            s.pop(); // '(' 더미 값 제거

            // 분수 y / z 계산
            long long yz_up = y.first * z.second;
            long long yz_down = y.second * z.first;
            long long gcd_yz = gcd(yz_up, yz_down);
            yz_up /= gcd_yz;
            yz_down /= gcd_yz;

            // 분수 x + (y / z) 계산
            long long result_up = x.first * yz_down + x.second * yz_up;
            long long result_down = x.second * yz_down;
            long long gcd_result = gcd(result_up, result_down);
            result_up /= gcd_result;
            result_down /= gcd_result;

            s.push(make_pair(result_up, result_down));
        }
        else {
            s.push(make_pair(stoll(token), 1)); // 숫자를 분수 형태로 변환
        }
    }

    if (s.size() != 1) {
        cout << -1 << endl;
    }
    else {
        cout << s.top().first << " " << s.top().second << endl;
    }

    return 0;
}
