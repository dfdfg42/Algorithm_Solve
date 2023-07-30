#include <iostream>
#include <vector>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> cnt(5);
    vector<int> ans;

    for (int k = 0; k < n; k++) {

        int sum = 0;
        int max = 0;
        for (int i = 0; i < 5; i++) {
            int input; cin >> input;
            cnt[i] = input;
            sum += input;
            //cout << cnt[i]<<"cnt";
        }
        //두개를 골라서 합에서 뺴기
        for (int z = 0; z < 5; z++) {
            for (int x = z; x < 5; x++) {
                if (z == x) continue;
                int temp = (sum - (cnt[z] + cnt[x])) % 10;
                if ( temp > max && temp<10) {
                    max = temp;
                }

            }
        }
        ans.push_back(max);
        //cout << max << "\n";
    }
    int sol = -1;
    int index = -1;
    for (int i = 0; i <ans.size(); i++) {
        if (ans[i] >= sol) {
            sol = ans[i];
            index = i;
            //cout << "i" << i << "\n";
        }
    }
    cout << index + 1; // << ":index";

    return 0;
}