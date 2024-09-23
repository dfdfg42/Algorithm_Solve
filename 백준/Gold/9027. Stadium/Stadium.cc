#include <vector>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; 
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> houses(n);
        for(int &x : houses) cin >> x;

        vector<int> fans(n);
        for(int &f : fans) cin >> f;

        // Find the weighted median
        long long total_fans = 0;
        for(auto f : fans) total_fans += f;

        long long half_fans = (total_fans + 1) / 2; // To handle even total_fans

        long long cumulative = 0;
        int best_house = houses[0];
        for(int i = 0; i < n; ++i){
            cumulative += fans[i];
            if(cumulative >= half_fans){
                best_house = houses[i];
                break;
            }
        }

        cout << best_house << '\n';
    }

    return 0;
}
