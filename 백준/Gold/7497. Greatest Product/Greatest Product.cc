#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

typedef long long ll;

int main() {



    string s;
    cin >> s;

    ll startMax = 1;

    for (int i = 0; i < s.length(); i++) {
        
        if (s[i] - '0' != 0) {
            startMax *= s[i] - '0';
        }
    }



    for (int i = 0; i < s.length(); i++) {

        ll tempMax = 1;
        if (s[i] - '0' - 1 != 0) { //1 내려서 0이면 곱하지 않고 넘어감
            tempMax *= s[i] - '0' - 1;
        }

        for (int j = i + 1; j < s.length(); j++) { //이후 자리수들 전부 9로 만들기

            tempMax *= 9;

        }

        for (int t = 0; t < i; t++) { //이전자리수들 곱해주기
            if(s[t] - '0' != 0)
                tempMax *= s[t] - '0';

        }

        startMax = max(tempMax, startMax);
    }

    cout << startMax << '\n';

    return 0;
}
