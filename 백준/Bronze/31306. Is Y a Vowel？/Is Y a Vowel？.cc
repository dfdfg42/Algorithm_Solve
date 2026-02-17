#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string word;
    cin >> word;

    int standardVowels = 0;
    int yCount = 0;        

    for (char c : word) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            standardVowels++;
        } else if (c == 'y') {
            yCount++;
        }
    }

    cout << standardVowels << " " << (standardVowels + yCount) << endl;

    return 0;
}