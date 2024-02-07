#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    string s;
    cin >> s;
    int count = 0;

    set<string> uniquePermutations; 
    sort(s.begin(), s.end()); 
    do {
        
        bool isValid = true;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) {
                isValid = false;
                break;
            }
        }
        if (isValid) {
            count++;
        }
    } while (next_permutation(s.begin(), s.end())); 

    cout << count << endl; 

    return 0;
}
