#include <iostream>
#include <vector>
#include <string>

using namespace std;



int main() {
    
    string input;

    getline(cin, input);
    

    for (int i = 0; i < input.length(); i++) {
        string temp;

        if (input.length() - i > 10) {
            temp = input.substr(i, 10);
            cout << temp << '\n';
            i += 9;
        }
        else {
            temp = input.substr(i, input.length() - i);
            cout << temp << '\n';
            break;
        }

    }

    return 0;
}
