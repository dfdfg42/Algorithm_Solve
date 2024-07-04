#include <iostream>
#include <string>
#include <algorithm> 
#include <map>


typedef long long ll;

using namespace std;

int divide(int factor) {
    if (factor % 2 == 1) {
        return factor;
    }
    else {
        return divide(factor / 2);
    }
}

int main() {
    
    int n;
    cin >> n;
    map<int, int> map;
    int freq = 0;
    while (n--) {
        int input;
        cin >> input;
        

        int odd = divide(input);

        if (map.find(odd) == map.end()) {
            map[odd] = 1;
        }
        else {
            map[odd]++;
        }

        freq = max(freq, map[odd]);

    }

    cout << freq<<'\n';

    return 0;
}
