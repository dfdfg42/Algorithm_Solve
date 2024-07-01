#include <iostream>
#include <string>
#include <algorithm> 
#include <map>

using namespace std;


int main() {
    int n;
    cin >> n;

    int b, w;
    cin >> b >> w;


    string s;
    cin >> s;


    int bw[2] = { 0,0 }; //0은 검정 1은 흰색
    map<char, int>color_map;
    color_map['W'] = 1;
    color_map['B'] = 0;
    int l = 0, r = 0;
    int maxlength = 0;

    while (r < n) {
        bw[color_map[s[r]]]++;
        r++;

 
        while (bw[0] > b ) {
            bw[color_map[s[l]]]--;
            l++;
        }

        if (bw[0] <= b && bw[1] >= w) {
            maxlength = max(maxlength, r - l);
        }
    }

    cout << maxlength << '\n';
    

    return 0;
}
