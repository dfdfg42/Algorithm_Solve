#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k;
    cin >> k;

    int n = 1;

    while (n < k) n <<= 1;

    cout << n << ' ';

    int cnt = 0;
    while (k != 0) {
        if (n <= k) {
            k -= n;
        }

        n >>= 1;

        if(k!=0)
        cnt++;
    }

    cout << cnt << '\n';

    return 0;
}