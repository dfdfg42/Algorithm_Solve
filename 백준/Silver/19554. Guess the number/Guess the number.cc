#include <iostream>
using namespace std;

int main() {
    long long N;
    cin >> N;

    long long left = 1, right = N;

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        cout << "? " << mid << endl;

        int response;
        cin >> response;

        if (response == 0) {
            cout << "= " << mid << endl;
            break;
        }
        else if (response == -1) {
            left = mid + 1;
        }
        else if (response == 1) {
            right = mid - 1;
        }
    }

    return 0;
}
