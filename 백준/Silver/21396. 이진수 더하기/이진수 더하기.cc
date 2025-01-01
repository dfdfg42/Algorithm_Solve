#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int n;
        long long x;
        cin >> n >> x;  

        vector<long long> numbers(n);
        for (int i = 0; i < n; i++) {
            cin >> numbers[i];
        }

        unordered_map<long long, long long> freq_map;
        for (int i = 0; i < n; i++) {
            freq_map[numbers[i]]++;
        }

        long long ans = 0; 
        for (int i = 0; i < n; i++) {
            long long target = numbers[i] ^ x;
            if (freq_map.find(target) != freq_map.end()) {
                ans += freq_map[target];
            }
        }

        if (x == 0) {
          
            ans = (ans - n) / 2;
        }
        else {

            ans /= 2;
        }

        cout << ans << "\n";
    }

    return 0;
}
