#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

typedef long long ll;


int main() {
    unordered_set<ll> cardSet;

    ll n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int input; 
        cin >> input;
        cardSet.insert(input);
    }

    ll m;
    cin >> m;
    vector<int> ans;
    for (int i = 0; i < m; i++) {

        int input;
        cin >> input;
        if (cardSet.find(input) == cardSet.end()) {
            ans.push_back(0);
        }
        else {
            ans.push_back(1);
        }
    }
    
    for (int i = 0; i < m; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}