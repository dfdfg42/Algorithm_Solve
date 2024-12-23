#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);



    while (true) {

        int m;
        cin >> m;
        if (m == 0) break;
        cin.ignore();

        string s;
        getline(cin ,s);


        map<char, int> cMap;
        int count = 0;
        int maxLen = 0;

        int l = 0;
        for (int r = 0; r < s.length(); r++) {


            if (++cMap[s[r]] == 1) {
                count++;
            }

            while (count > m) {
                if (--cMap[s[l]] == 0) {
                    count--;
                }
                l++;  
            }

            maxLen = max(r - l + 1, maxLen);
        }

        cout << maxLen << '\n';

    }
    

    return 0;
}
