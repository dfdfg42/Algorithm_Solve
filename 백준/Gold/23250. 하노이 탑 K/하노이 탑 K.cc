#include <iostream>
using namespace std;
typedef long long ll;


pair<int, int> findKthMove(int n, int from, int to, int aux, ll k) {

    if (n == 1) {
        return { from, to };
    }


    ll moves = (1LL << (n - 1)) - 1;

    if (k <= moves) {
        return findKthMove(n - 1, from, aux, to, k);
    }
 
    else if (k == moves + 1) {
        return { from, to };
    }
    else {
        return findKthMove(n - 1, aux, to, from, k - moves - 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll k;
    cin >> n >> k;


    pair<int, int> result = findKthMove(n, 1, 3, 2, k);

    cout << result.first << " " << result.second << endl;

    return 0;
}