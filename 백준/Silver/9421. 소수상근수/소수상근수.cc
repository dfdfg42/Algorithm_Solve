#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <cstring>
#include <set>
#include <cmath>

using namespace std;

typedef long long ll;
typedef long double ld;

int n;

vector<bool> prime;
vector<int> primes;
set<int> canOnes;

bool becomeOne(string input) {
    set<int> s;
    bool find = false;

    while (!find) {


        int temp = 0;
        for (int i = 0; i < input.length(); i++) {
            temp += pow(input[i] - '0',2);
            //cout << temp << '\n';
        }
        if (temp == 1) {
            find = true;
        }
        else if(s.find(temp)!= s.end()){
            break;
        }
        else {
            s.insert(temp);
        }

        input = to_string(temp);

    }

    return find;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    prime.resize(n + 1,false);

    for (int i = 2; i <= n; i++) {
        if (!prime[i]) {
            prime[i] = true;
            //cout << i << '\n';
            primes.push_back(i);
            for (int j = i; j <= n; j += i) {
                prime[j] = true;
            }
        }
    }

    //becomeOne("7");

    for (auto& a : primes) {
        if (becomeOne(to_string(a))) {
            cout << a << '\n';
        }
    }

    return 0;
}