#include <iostream>
#include <stack>
#include <cctype> 
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    vector<pair<int,int>> inputs(n);

    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        inputs[i] = { input,i };
    }
    sort(inputs.begin(), inputs.end());


    vector<int> index(n);
    int rank = 0; 
    int last = INT_MIN; 

   
    for (int i = 0; i < n; i++) {
        if (i != 0 && inputs[i].first != inputs[i - 1].first) {
            rank ++;
        }
        index[inputs[i].second] = rank; 
        last = inputs[i].first; 
    }

    for (int k : index) {
        cout << k << ' ';
    }

    return 0;
}
