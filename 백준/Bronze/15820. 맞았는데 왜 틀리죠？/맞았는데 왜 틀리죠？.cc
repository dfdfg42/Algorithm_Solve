#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

typedef long long ll;


int main() {

    ll s1, s2;

    cin >> s1 >> s2;

    bool c1 = true; 
    bool c2 = true;
    for (int i = 0; i < s1; i++) {
        ll a, b;
        cin >> a >> b;
        if (a != b) c1 = false;

    }

    for (int i = 0; i < s2; i++) {
        ll a, b;
        cin >> a >> b;
        if (a != b) c2 = false;
    }
    //cout << c1 << ' ' << c2 << '\n';

    if (c1 && c2) cout << "Accepted\n";
    else if (c1 && !c2) cout << "Why Wrong!!!\n";
    else if (!c1 && !c2) cout << "Wrong Answer\n";
    else if (!c1 && c2) cout << "Wrong Answer\n";

    
    return 0;
}