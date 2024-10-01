#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>

using namespace std;



int main() {

    int t; cin >> t;

    while (t--) {
        string s;
        cin >> s;

        bool fall = false;
        char fix;
        bool isfix = false;
        for (int i = 1; i < s.length(); i++) {

            if (!fall) {
                if (s[i] - '0' < s[i - 1] - '0') {
                    fall = true;
                    fix = s[i];
                }
            }
            else {

                if (!isfix) {
                    if (s[i] - '0' > s[i - 1] - '0') { //더 커지는 순간 고정
                        s[i] = fix;
                        isfix = true;

                    }
                    else { //더 작아지면
                        //s[i] = s[i - 1];
                        fix = s[i];
                    }
                }
                else {
                    s[i] = fix;
                }

            }
        }

        cout << s << '\n';
    }

    

    return 0;
}
