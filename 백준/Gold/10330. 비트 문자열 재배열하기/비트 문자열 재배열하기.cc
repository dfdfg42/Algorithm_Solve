#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <cstring>
#include <set>
#include <cmath>
#include <climits>


using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = 987654321;

ll n, m;

vector<int> vec;
vector<int> target;
vector<int> ans1;
vector<int> ans2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    vec.resize(n);
    target.resize(m);
    int vecOnes = 0;
    int ans1Ones = 0;
    int ans2Ones = 0;
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
        if (vec[i] == 1) vecOnes++;
    }
    for (int i = 0; i < m; i++) {
        cin >> target[i];
    }

    bool rev = false;
    for (auto a : target) {
        while (a > 0) {
            ans1.push_back(rev);
            if (rev == true) ans1Ones++;
            ans2.push_back(!rev);
            if (rev == false) ans2Ones++;
            a--;
        }
        rev = !rev;
    }

    //for (auto a : ans1) {
    //    cout << a  ;
    //}
    //cout << '\n';
    //for (auto a : ans2) {
    //    cout << a;
    //}
    //cout << '\n';

    vector<bool> used1(n, false);
    vector<bool> used2(n, false);
    int val1 = 0;
    int val2 = 0;

    for (int i = 0; i < n; i++) {
        if (vec[i] == 1) {
            for (int j = 0; j < n; j++) {
                if (ans1[j] == 1 && !used1[j]) {
                    used1[j] = true;
                    val1 += abs(i - j);
                    //cout << "j : " << j << '\n';
                    break;
                }
            }

        }
        if (vec[i] == 1) {
            for (int j = 0; j < n; j++) {
                if (ans2[j] == 1 && !used2[j]) {
                    used2[j] = true;
                    val2 += abs(i - j);
                    //cout << "j2 : " << j << '\n';
                    break;
                }
            }

        }
    }

    if (ans1Ones != vecOnes) val1 = INF;
    if (ans2Ones != vecOnes) val2 = INF;

    //cout << val1 << ' ' << val2 << '\n';
    int tmp = min(val1, val2);
    cout << tmp << '\n';

    return 0;
}