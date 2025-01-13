#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> vec(N);
    for (int i = 0; i < N; i++) {
        cin >> vec[i];
    }

   
    unordered_map<int, int> freqMap;


    long long answer = 0;  
    int l = 0;             

    
    for (int r = 0; r < N; r++) {
        
        freqMap[vec[r]]++;

        while (freqMap[vec[r]] > 1) {
            freqMap[vec[l]]--;
            l++;
        }

 
        answer += (r - l + 1);
    }

    cout << answer << "\n";
    return 0;
}
