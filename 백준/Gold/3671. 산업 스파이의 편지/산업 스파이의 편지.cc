#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

static const int MAX = 10'000'000;
bool primeArr[MAX];    
set<int> primeSet;    

string s;
set<int> madeNumbers;   

void sieveOfEratosthenes() {
    primeArr[0] = false;
    primeArr[1] = false;

    for (int i = 2; i < MAX; i++) {
        primeArr[i] = true;
    }

    for (int i = 2; i * i < MAX; i++) {
        if (primeArr[i]) {
            for (int j = i * i; j < MAX; j += i) {
                primeArr[j] = false;
            }
        }
    }
}


void dfs(string& input, vector<bool>& used, int length) {

    if ((int)input.size() == length) {
  
        int num = stoi(input);
        madeNumbers.insert(num);
        return;
    }


    for (int i = 0; i < (int)s.size(); i++) {
        if (!used[i]) {
            used[i] = true;
            input.push_back(s[i]);

            dfs(input, used, length);

            input.pop_back();
            used[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    sieveOfEratosthenes();


    int t;
    cin >> t;
    while (t--) {
        cin >> s;
        madeNumbers.clear();


        for (int len = 1; len <= (int)s.size(); len++) {
            vector<bool> used(s.size(), false);
            string tmp;
            dfs(tmp, used, len);
        }


        int Pcount = 0;
        for (int num : madeNumbers) {
            if (primeArr[num]) {
                Pcount++;
            }
        }

        cout << Pcount << "\n";
    }
    return 0;
}
