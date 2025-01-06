#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long p, n;
    cin >> p >> n;  

    vector<long long> problems(n);
    for (int i = 0; i < n; i++) {
        cin >> problems[i];
    }

    sort(problems.begin(), problems.end());

    long long sum = 0;         
    long long count = 0;            
    vector<long long> solveProblems;

  
    for (int i = 0; i < n; i++) {
        if (sum + problems[i] < p) { 
            sum += problems[i];
            solveProblems.push_back(problems[i]);
            count++;
        } else {
            break;
        }
    }

    
    long long gap = p - sum - 1;  
    long long ans = 0;

    for (int i = (int)solveProblems.size() - 1; i >= 0; i--) {
        ans += (gap + solveProblems[i]);
        gap += solveProblems[i];
    }

    cout << count << " " << ans << "\n";
    return 0;
}
