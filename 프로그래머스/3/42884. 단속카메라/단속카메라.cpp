#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {

    sort(routes.begin(), routes.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });

    int cctv = 0;
    int lastCamera = -30001; 

    for (const auto& route : routes) {
        if (route[0] > lastCamera) { 
            lastCamera = route[1];
            cctv++;
        }
    }

    return cctv;
}
