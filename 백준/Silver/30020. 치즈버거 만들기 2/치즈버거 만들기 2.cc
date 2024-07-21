#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>
#include<queue>
#include<unordered_map>
#include <unordered_set>
using namespace std;
int x, y, buger, set;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> x >> y;
    set = y; // 패티 치즈 쌍
    buger = (x - y); //최소 버거갯수
    if (y >= x) {
        cout << "NO";
    }
    else if (buger > set)
    {
        cout << "NO";
    }
    else {
        cout << "YES" << "\n";
        cout << buger << "\n";
        for (int i = 0; i < buger; i++)
        {
            if (i == buger - 1) {
                for (int i = 0; i < set; i++)
                {
                    cout << "ab";
                }
                cout << "a" << "\n";
            }
            else
            {
                cout << "aba" << "\n";
                set--;
            }
        }


    }

    return 0;
}
