#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
typedef long long ll;

using namespace std;




ll result, A,B,C;
ll calc(ll a, ll b) {

    if (b == 0) return 1;
    if (b == 1) return a;



    ll result = (calc(a, b / 2) * calc(a, b / 2))%C;
    
    if (b % 2 == 1) (result = result * a)%C;
    

    return (result%C);
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B >> C;


    cout << calc(A, B) % C;
    
}
