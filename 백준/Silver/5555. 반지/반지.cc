#include <iostream>
#include <vector>
#include <cmath> 
#include <queue>
using namespace std;

string target;
int n;
vector<string> inputs;
int ans;

void findTarget(string& s) {


    for (int i = 0; i < s.length(); i++) {
        bool find = true;
        for (int j = 0; j < target.length(); j++) {
            if (s[(i + j) % s.length()] != target[j]) {
                find = false;
                break;
            }
        }
        if (find) {
            ans++;
            return;

        }

    }

    return;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> target;
    cin >> n;
    ans == 0;
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;

        findTarget(input);
        //cout << ans << '\n';
    }

    cout << ans << '\n';

    return 0;
}