#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <iomanip>
#include <tuple>
#include <sstream>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> basket(N+1, 0);

    for (int i = 1; i <= N; i++) {
        basket[i] = i;
    }

    for (int t = 0; t < M; t++) {
        int i, j;
        cin >> i >> j ;

        int temp = basket[i];
        basket[i] = basket[j];
        basket[j] = temp;
    }
    
    for (int i = 1; i <= N; i++) {
        cout << basket[i] << ' ';
    }

    return 0;
}
