#include <iostream>
#include <string>
#include <istream>
#include <vector>
#include <algorithm>
using namespace std;

int cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    else {
        return a.second < b.second;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int n;
    cin >> n;
    vector<pair<int, int>> str;


    while (n--) {
        int input, input2;
        cin >> input >> input2;
        str.push_back({ input,input2 });
    }
    sort(str.begin(), str.end(), cmp);

    for (int i = 0; i < str.size(); i++) {
        cout << str[i].first << " " << str[i].second << "\n";

    }



    return 0;
}