#include <iostream>
#include <algorithm>

using namespace std;

int zeroCount[41] = { 1, 0, };
int oneCount[41] = { 0, 1, };
int container[41] = { 0, 1, };
bool check[41] = { true, true, };

int fibonacci(int input) {
    if (check[input]) {
        return container[input];
    }

    check[input] = true;
    container[input] = fibonacci(input - 1) + fibonacci(input - 2);

    zeroCount[input] = zeroCount[input - 1] + zeroCount[input - 2];
    oneCount[input] = oneCount[input - 1] + oneCount[input - 2];

    return container[input];
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        int input;
        cin >> input;

        fibonacci(input);
        cout << zeroCount[input] << " " << oneCount[input] << "\n";
    }
}
