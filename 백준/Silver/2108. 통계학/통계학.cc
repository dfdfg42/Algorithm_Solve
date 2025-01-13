#include <iostream>
#include <vector>
#include <map>
#include <algorithm>  
#include <cmath>      
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> vec(n);
    
    map<int, int> countMap;

    long long sum = 0; 

    
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
        sum += vec[i];
        countMap[vec[i]]++;
    }

   
    double mean = (double)sum / n;
    int average = (int)round(mean);

  
    sort(vec.begin(), vec.end());
    int median = vec[n / 2];

    
    int maxFreq = 0;

    for (auto& p : countMap) {
        if (p.second > maxFreq) {
            maxFreq = p.second;
        }
    }

    vector<int> modes;
    for (auto& p : countMap) {
        if (p.second == maxFreq) {
            modes.push_back(p.first);
        }
    }

    sort(modes.begin(), modes.end());
    int mode = 0;
    if (modes.size() == 1) {
        mode = modes[0];
    }
    else {
        mode = modes[1];
    }


    int range = vec.back() - vec.front();


    cout << average << '\n'  
        << median << '\n'   
        << mode << '\n'     
        << range << '\n';    

    return 0;
}
