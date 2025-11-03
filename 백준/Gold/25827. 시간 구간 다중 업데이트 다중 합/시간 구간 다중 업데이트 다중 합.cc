#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <string>
using namespace std;

typedef long long ll;


vector<long long> timeVector;

int getTimeIndex(const string& s) {
    int h = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3, 2));
    int se = stoi(s.substr(6, 2));
    return h * 3600 + m * 60 + se; 
}


void doImos() {
    for (int i = 1; i < (int)timeVector.size(); i++) {
        timeVector[i] += timeVector[i - 1];
    }
}


void doPrefixSum() {
    for (int i = 1; i < (int)timeVector.size(); i++) {
        timeVector[i] += timeVector[i - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    const int T = 86400;           
    timeVector.assign(T, 0);        
    bool cal = false;

    for (int i = 0; i < n; i++) {
        int type;
        string a, b;
        cin >> type >> a >> b;      

        if (type == 1) {
            
            int start = getTimeIndex(a);
            int end = getTimeIndex(b);
            timeVector[start] += 1;
            if (end < T) timeVector[end] -= 1; 
        }
        else { 
            if (!cal) {
                doImos();          
                doPrefixSum();      
                cal = true;
            }
            int start = getTimeIndex(a);
            int end = getTimeIndex(b); 
           
            long long ans = (end > 0 ? timeVector[end - 1] : 0) - (start > 0 ? timeVector[start - 1] : 0);
            cout << ans << '\n';
        }
    }
    return 0;
}
