#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;



int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        int a = m * 2;
        int cut = a - n;
        //cout << " a : " << a << '\n';

        cout << cut << ' ' << m - cut << '\n';
    }

    
    return 0;
}