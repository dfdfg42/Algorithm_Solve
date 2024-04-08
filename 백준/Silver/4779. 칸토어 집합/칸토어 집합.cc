#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

void fillCantorSet(string& cantorSet, int start, int end) {
    if (end - start == 0) {
        return; 
    }
    int segmentLength = (end - start + 1) / 3;

    
    for (int i = start + segmentLength; i < start + 2 * segmentLength; i++) {
        cantorSet[i] = ' ';
    }

    
    fillCantorSet(cantorSet, start, start + segmentLength - 1);
    fillCantorSet(cantorSet, start + 2 * segmentLength, end);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n) {
        int length = pow(3, n); 
        string cantorSet(length, '-'); 
        fillCantorSet(cantorSet, 0, length - 1);
        cout << cantorSet << "\n"; 
    }
    return 0;
}
