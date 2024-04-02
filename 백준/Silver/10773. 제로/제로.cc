#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>
using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K;
    cin >> K;
    int result = 0;

    vector<int> stack;

    for (int i = 0; i < K; i++) {
        int input;
        cin >> input;  


        if (input == 0) {
            result -= stack.back();
            stack.pop_back();
        }
        else {
            result += input;

            stack.push_back(input);
        }


    }

    cout << result << '\n';

    return 0;
}
