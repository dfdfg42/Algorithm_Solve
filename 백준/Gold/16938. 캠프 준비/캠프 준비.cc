#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

typedef long long ll;

int N, L, R, X;

vector<int> difficulty;

int ans;

void dfs(int index,  int minDif, int maxDif , ll sumDif) {

    

    if (index == N) {

        if (maxDif - minDif < X || sumDif > R || sumDif < L) return;

        ans++;

        return;
    }


    //선택 안하는경우 
    dfs(index + 1, minDif, maxDif, sumDif);

    minDif = min(minDif, difficulty[index]);
    maxDif = max(maxDif, difficulty[index]);

    //선택하는경우 
    dfs(index + 1, minDif, maxDif, sumDif + difficulty[index] );

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> L >> R >> X;

    ans = 0;
    difficulty.resize(N);
    for (int i = 0; i < N; i++){
        cin >> difficulty[i];
    }

    vector<int> a;
    dfs(0, INT_MAX, 0, 0);

    cout << ans << '\n';

    return 0;
}