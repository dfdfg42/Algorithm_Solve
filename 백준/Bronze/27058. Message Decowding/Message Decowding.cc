#include<iostream>
#include<string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char dec[26];
    string key, message;

    cin >> key;
    for (int i = 0; i < 26; i++) {
        dec[i] = key[i];
    }

    cin.ignore(); 
    getline(cin, message);

    string result;
    for (char c : message) {
        if (isupper(c)) {
            result += toupper(dec[c - 'A']);
        }
        else if (islower(c)) {
            result += dec[c - 'a'];
        }
        else {
            result += c;
        }
    }

    cout << result << '\n';

    return 0;
}
