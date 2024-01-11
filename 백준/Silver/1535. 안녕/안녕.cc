#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

struct person {
    int life;
    int joy;
};

int main() {
    int N; 
    cin >> N;
    
    vector<person> persons(N + 1, {0, 0});

    for (int i = 1; i <= N; i++) {
        cin >> persons[i].life;
    }
    for (int i = 1; i <= N; i++) {
        cin >> persons[i].joy;
    }

    vector<vector<int>> dp(N + 1, vector<int>(101, 0));

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= 99; j++) {
           if (persons[i].life > j) {
               dp[i][j] = dp[i - 1][j];
           }
           else {
               dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - persons[i].life] + persons[i].joy);
           }
        }
    }

    cout << dp[N][99];

    return 0;
}
