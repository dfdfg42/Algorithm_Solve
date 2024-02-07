#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <set>
using namespace std;





int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<string> vec;

    for (int i = 0; i < N; i++) {
        string input; cin >> input;
        vec.push_back(input);
    }

    for (int i = 0; i < N; i++) {
        string s = vec[i];
        sort(s.begin(),s.end());
        set<string> stringSet;
        do {
            if(stringSet.find(s) == stringSet.end()){
                cout << s << '\n';
            }
            else {
                stringSet.insert(s);
            }

        } while (next_permutation(s.begin(), s.end()));

    }



    return 0;
}
