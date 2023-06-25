#include <iostream>
#include <string>
#include <istream>
#include <vector>
using namespace std;

int Group(int& count) {
    string str;
    cin >> str;
    bool group = true;
    bool alp[26] = {false, };

    for (int i = 0; i < str.size(); i++) {
        if (i > 0) {
            if (str[i] != str[i - 1] && alp[str[i] - 97] == true) {
                group = false;
                break;
            }
        }

        alp[str[i] - 97] = true;

    }
    if (group) {
        count++;
    }


    return 0;
}


int main() {



    int n;
    cin >> n;
    int count = 0;

    while (n--) {
        Group(count);
    }
    cout << count;

    return 0;
}