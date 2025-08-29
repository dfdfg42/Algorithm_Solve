#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <set>
#include <cmath>
using namespace std;

typedef unsigned long long ll;
typedef long double ld;

int N, P;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> P;
    
    int cnt = 0;
    int line = -1;
    vector<vector<int>> pret(7);
    for (int i = 0; i < N; i++) {
        int n, p;
        cin >> n >> p;


        if (pret[n].empty()) {
            pret[n].push_back(p);
            cnt++;
        }
        else if ( pret[n].back() <= p) {
            if (pret[n].back() == p) continue;

            pret[n].push_back(p);
            cnt++;
        }
        else if ( pret[n].back() > p) {
            while (!pret[n].empty() && pret[n].back() > p) {
                cnt++;
                pret[n].pop_back();
            }
            if (pret[n].empty()) {
                pret[n].push_back(p);
                cnt++;
            }
            else if (pret[n].back() == p) continue;
            else { 
                pret[n].push_back(p);
                cnt++;
            }


        }

        //cout << "n : " << n << " cnt : " << cnt << "\n";
    }


    cout << cnt << '\n';

    return 0;
}