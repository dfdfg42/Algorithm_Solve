#include<vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> vec;
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        vec.push_back(input);
    }
    sort(vec.begin(), vec.end());

    for (int a : vec) {
        cout << a << "\n";
    }
}

