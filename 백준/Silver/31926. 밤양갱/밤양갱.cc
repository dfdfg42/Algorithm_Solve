#include <iostream>
#include <vector>
using namespace std;



int main() {
    
    int n;
    cin >> n;

    int count = 0;
    if (n == 1) {
        count = 10;
    }
    else if (n == 2) {
        count = 11;
    }
    else if (n >= 3) {
        int temp = 1;
        while (temp <= n) {
            if (temp * 2 <= n) {
                temp *= 2;
                count++;
            }
            else{
                count += 2;
                break;
            }
        }
        count += 8;
    }

    cout << count << '\n';
    return 0;
}
