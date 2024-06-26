#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>

using namespace std;


const int MAX = 100'000;

bool check[MAX + 1];
vector<int> primes;
vector<int> factors;

void Factorization(int num) {

    for (int i : primes) {
        if (num % i == 0) {
            factors.push_back(i);
            Factorization(num / i);
            break;
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);



    for (int i = 2; i <= MAX; i++) {

        if (check[i] == false) {
            primes.push_back(i);

            for (int j = i; j <= MAX; j += i) {
                if (check[j] == false) {
                    check[j] = true;

                }
            }
        }

    }


    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int a;
        cin >> a;


        Factorization(a);

        map<int, int> factorCount;
        for (int f : factors) {
            if (factorCount.find(f) != factorCount.end()) {
                factorCount[f]++;
            }
            else {
                factorCount[f] = 1;
            }
        }

        for ( auto& pair : factorCount) {
            cout << pair.first << " " << pair.second << '\n';
        }

        factors.clear();
        factorCount.clear();
    }

    return 0;
}
