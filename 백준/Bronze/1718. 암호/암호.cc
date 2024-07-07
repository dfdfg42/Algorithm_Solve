#include <iostream>
#include <string>

using namespace std;

int main() {
    string plaintext;
    getline(cin, plaintext);
    string key;
    cin >> key;
    string result(plaintext.length(), ' ');

    for (int i = 0; i < plaintext.length(); i++) {
        if (plaintext[i] == ' ') {
            result[i] = ' ';
        }
        else {
            char tmp = plaintext[i] - (key[i % key.length()] - 'a') - 1;
            if (tmp < 'a') {
                tmp += 26;
            }
            result[i] = tmp;
        }
    }

    cout << result << '\n';

    return 0;
}
