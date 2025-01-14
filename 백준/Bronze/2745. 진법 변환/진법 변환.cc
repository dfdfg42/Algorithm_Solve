
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    string N; 
    int B;   
    cin >> N >> B;

    long long result = 0; 
    int power = 0;        

 
    for (int i = N.size() - 1; i >= 0; i--) {
        char c = N[i];
        int digit;

        if (c >= '0' && c <= '9') {
            digit = c - '0';
        }
        else {
            digit = c - 'A' + 10; 
        }

        result += digit * pow(B, power); 
        power++;
    }

    cout << result << endl; 
    return 0;
}