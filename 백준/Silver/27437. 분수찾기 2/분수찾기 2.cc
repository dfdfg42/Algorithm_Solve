#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll x;
    cin >> x;


    ll index = 1;
    ll cnt = 0;
    while (index + cnt <= x) {
        index += cnt;
        cnt++;
    }


    ll diff = x - index;

    ll head;  
    ll child; 


    if (cnt % 2 == 1) { 
        head = cnt - diff;
        child = 1 + diff;
    } else {
        head = 1 + diff;
        child = cnt - diff;
    }

    cout << head << "/" << child << '\n';

    return 0;
}