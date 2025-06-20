#include <iostream>
#include <vector>
#include <cmath>

const int MAX_N = 100000000;

std::vector<bool> is_prime(MAX_N + 1, true);


void sieve(int n) {
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= n; ++p) {
        if (is_prime[p]) {

            for (int i = p * p; i <= n; i += p) {
                is_prime[i] = false;
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    sieve(n);


    unsigned int result = 1;


    for (int p = 2; p <= n; ++p) {

        if (is_prime[p]) {
            long long power_of_p = p;
            while (power_of_p <= n / p) {
                power_of_p *= p;
            }

            result *= (unsigned int)power_of_p;
        }
    }

    std::cout << result << std::endl;

    return 0;
}