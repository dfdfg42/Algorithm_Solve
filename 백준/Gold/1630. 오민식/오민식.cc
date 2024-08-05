#include <iostream>
#include <string>
#include <istream>
#include <vector>
#include <algorithm>
using namespace std;
bool check[1000001];



typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int>primes;



    //n이하의 소수들 전부 찾기
    for (int i = 2; i <= n; i++) {
        if (check[i] == false) {
            primes.push_back(i);
            for (int j = i; j <= n; j += i) {
                if (check[j] == false) {
                    check[j] = true;
                }
            }
        }
    }


    ll result = 1;
    for (int p : primes) {
        ll temp = p;

        while (temp * p <= n) {
            temp *= p;
        }
        //cout << "temp:" << temp << '\n';
        result *= temp;
        result %= 987654321;
    }

    cout << result << '\n';


    return 0;
}