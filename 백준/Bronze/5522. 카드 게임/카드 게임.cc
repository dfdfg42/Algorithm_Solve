#include <iostream>
using namespace std;

int main() {
    int sum = 0, x;
    for (int i = 0; i < 5; i++) {
        cin >> x;
        sum += x;
    }
    cout << sum << '\n';
    return 0;
}