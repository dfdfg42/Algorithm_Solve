#include <iostream>
#include <string>
#include <istream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1000000;
bool check[MAX + 1];
int pn;
int prime[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 2; i <= MAX; i++) {
        if (check[i] == false) {
            prime[pn++] = i;
            for (int j = i + i; j <= MAX; j += i) {
                check[j] = true;
            }
        }
    }

    int k;
    cin >> k;
    cout << prime[k-1];

}