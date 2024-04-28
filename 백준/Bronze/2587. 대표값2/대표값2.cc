#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    vector<int> vec;
    int total = 0;
    for (int i = 0; i < 5; i++) {
        int input; cin >> input;
        total += input;
        vec.push_back(input);
    }
    sort(vec.begin(), vec.end());

    cout << total / 5 << '\n' << vec[2] ;

    return 0;
}
