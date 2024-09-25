#include <iostream>
#include <vector>
using namespace std;

vector<int> divisorCount(1000001, 0);  // Number of divisors for each number
vector<int> spd(1000001, 0);  // Smallest proper divisor (>1) for each number

// Precompute number of divisors and smallest proper divisors
void precompute() {
    // Calculate the number of divisors for each number
    for (int i = 1; i <= 1000000; i++) {
        for (int j = i; j <= 1000000; j += i) {
            divisorCount[j]++;
        }
    }

    // Calculate the smallest proper divisor (>1) for each number
    for (int i = 2; i <= 1000000; i++) {
        if (spd[i] == 0) {
            // i is a prime number; it doesn't have a proper divisor greater than 1
            for (int j = i + i; j <= 1000000; j += i) {
                if (spd[j] == 0) {
                    spd[j] = i;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    precompute();  // Precompute divisor counts and smallest proper divisors

    int t;
    cin >> t;

    for (int case_num = 1; case_num <= t; case_num++) {
        int n, m;
        cin >> n >> m;

        int present = 0;
        int nYoungerBrothers = divisorCount[n] - 1;  // Number of younger brothers of n

        for (int i = 2; i < n; i++) {
            int iYoungerBrothers = divisorCount[i] - 1;

            if (iYoungerBrothers == nYoungerBrothers && iYoungerBrothers > 0) {
                // i is a younger sister of n
                if (spd[i] >= m) {
                    present++;
                }
            }
        }

        cout << "Case #" << case_num << ": " << present << endl;
    }

    return 0;
}
