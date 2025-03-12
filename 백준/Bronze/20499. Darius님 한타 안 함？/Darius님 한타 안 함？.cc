#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    stringstream ss(s);
    string temp;
    vector<string> token;

    while (getline(ss,temp , '/')) {
        token.push_back(temp);
        
    }

    if (stoi(token[0]) + stoi(token[2]) < stoi(token[1]) || stoi(token[1]) == 0) {
        cout << "hasu" << '\n';

    }
    else {
        cout << "gosu" << '\n';
    }

    return 0;
}
