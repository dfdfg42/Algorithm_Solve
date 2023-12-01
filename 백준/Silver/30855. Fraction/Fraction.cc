#include <iostream>
#include <stack>
#include <utility>
#include <vector>
#include <sstream>

using namespace std;

typedef pair<long long, long long> frac;

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

frac add(frac x, frac y) {
    long long pa = x.first * y.second + x.second * y.first;
    long long pb = x.second * y.second;
    long long k = gcd(pa, pb);
    return make_pair(pa / k, pb / k);
}

frac gl(frac x, frac y) {
    long long pa = x.first * y.second;
    long long pb = x.second * y.first;
    long long k = gcd(pa, pb);
    return make_pair(pa / k, pb / k);
}

frac sv(frac x, frac y, frac z) {
    return add(x, gl(y, z));
}

int main() {
    int n;
    cin >> n;
    cin.ignore();

    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    stack<frac> s;

    for (auto& i : a) {
        if (i == ")") {
            if (s.size() < 4) {
                cout << -1 << endl;
                return 0;
            }

            frac z = s.top(); s.pop();
            frac y = s.top(); s.pop();
            frac x = s.top(); s.pop();

            if (s.top().first != -1) {
                cout << -1 << endl;
                return 0;
            }
            s.pop();

            s.push(sv(x, y, z));
        } else {
            if (i == "(") {
                s.push(make_pair(-1, -1)); // '('를 표시하기 위한 더미 값
            } else {
                s.push(make_pair(stoll(i), 1));
            }
        }
    }

    if (s.size() != 1) {
        cout << -1 << endl;
    } else {
        cout << s.top().first << " " << s.top().second << endl;
    }

    return 0;
}
