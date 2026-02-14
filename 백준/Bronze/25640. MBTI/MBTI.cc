#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string jinhoMBTI;
    int n;
    int count = 0;

    cin >> jinhoMBTI;

    cin >> n;

    for (int i = 0; i < n; i++) {
        string friendMBTI;
        cin >> friendMBTI;

        if (jinhoMBTI == friendMBTI) {
            count++;
        }
    }

    cout << count << "\n";

    return 0;
}