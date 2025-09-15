#include <iostream>
#include <vector>
#include <iomanip> 
#include <queue>
#include <algorithm>

using namespace std;

typedef long double ld;
typedef long long ll;

vector<ll> primes;
vector<bool> visited;
vector<int> Prime;

ll n;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    visited.resize(5'000'001 ,false);
    Prime.resize(5'000'001, -1);
    for (ll i = 2; i < 5'000'001; i++) {
        if (visited[i] == false) {
            visited[i] = true;
            for (ll j = i; j < 5'000'001 ; j += i) {
                visited[j] = true;
                if(Prime[j] == -1)
                Prime[j] = i;
            }
        }
        
    }



    cin >> n;
    for (int i = 0; i < n; i++) {
        ll input;
        cin >> input;

        while (input > 1) {
            cout << Prime[input] << ' ';
            input /= Prime[input];

        }
        cout << '\n';
    }

    return 0;
}