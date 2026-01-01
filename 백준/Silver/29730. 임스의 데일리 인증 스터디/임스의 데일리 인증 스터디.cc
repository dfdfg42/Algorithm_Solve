#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;

struct compare {

    bool operator()(const string& a, const string& b) {

        if (a.length() != b.length()) {
            return a.length() < b.length();
        }

        return a < b;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    cin.ignore();

    vector<string> other;
    vector<string> baek;
    for (int i = 0; i < n; i++) {

        string s;
        getline(cin, s);


        bool flag = false;
        for (auto a : s) {
            if (a == '/') {
                flag = true;
                break;
            }
        }

        if (flag) {
            baek.push_back(s);
        }
        else other.push_back(s);

       // cout << i << ' ' << s << '\n';

    }

    sort(other.begin(), other.end(),compare());
    sort(baek.begin(), baek.end() ,compare() );

    for (auto a : other) {
        cout << a << '\n';
    }
    for (auto a : baek) {
        cout << a << '\n';
    }

    return 0;
}