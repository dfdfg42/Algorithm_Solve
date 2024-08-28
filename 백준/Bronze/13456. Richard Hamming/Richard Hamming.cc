#include <iostream>
#include <vector>
using namespace std;

int main() {
   
    int t;
    cin >> t;

    while (t--) {

        int n; cin >> n;

        vector<int> vec1(n);
        vector<int> vec2(n);

        for (int i = 0; i < n; i++) {
            cin >> vec1[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> vec2[i];
        }

        int count = 0;

        for (int i = 0; i < n; i++) {
            if (vec1[i] != vec2[i]) {
                count++;
            }
        }

        cout << count << '\n';

    }

    return 0;
}
