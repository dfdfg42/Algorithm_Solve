#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long n;  
        cin >> n;

        long long count = 0;


        for (long long i = 5; n / i > 0; i *= 5) {
            count += n / i;

            if (i > n / 5) break;
        }

        cout << count << '\n';
    }

    return 0;
}