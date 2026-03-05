#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    
    string s;
    string s1;
    cin >> s >> s1;

    
    string stack;

    for (int i = 0; i < s.length(); i++) {

        stack.push_back(s[i]);

        if (stack.length() >= s1.length()) {

            if (stack.compare(stack.length() - s1.length() , s1.length(), s1) == 0) {
                stack.erase(stack.length() - s1.length(), s1.length());
            }
            
        }

    }

    cout << (stack.empty() ? "FRULA" : stack) << '\n';

    return 0;
}