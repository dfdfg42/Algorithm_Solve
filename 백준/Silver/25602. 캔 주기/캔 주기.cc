#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cmath>
using namespace std;

typedef long long ll;
typedef long double ld;


int n, k;

vector<int> A;
vector<vector<int>> R;
vector<vector<int>> M;

int maxPoint;

void dfsMarry(int depth, int point, vector<int> cans, int Rpoint) {

    //k일동안 먹을거 다 골랐으면.
    if (depth == k) {

        maxPoint = max(maxPoint, point + Rpoint);

        return;
    }

    //select number
    for (int i = 0; i < n; i++) {

        //캔의 개수가 1개는 있어야댐
        if (cans[i] == 0) {
            continue;
        }

        cans[i]--;
        dfsMarry(depth + 1, point + M[depth][i], cans , Rpoint);
        cans[i]++;
    }

    return;
}

void dfsRang(int depth, int point, vector<int> cans) {


    //k일동안 먹을거 다 골랐으면.
    if (depth == k) {

        dfsMarry(0, 0, cans, point);

        return;
    }

    //select number
    for (int i = 0; i < n; i++) {
        
        //캔의 개수가 1개는 있어야댐
        if (cans[i] == 0) {
            continue;
        }

        cans[i]--;
        dfsRang(depth +1, point + R[depth][i], cans);
        cans[i]++;
    }

    return;
}




void solve() {

    cin >> n >> k;
    A.resize(n);
    for(int i=0; i<n;i++){
        cin >> A[i];
    }


    R.resize(k, vector<int>(n));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cin >> R[i][j];
        }
    }

    M.resize(k, vector<int>(n));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cin >> M[i][j];
        }
    }

    maxPoint = 0;


    dfsRang(0, 0, A);

    cout << maxPoint << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    solve();



    return 0;
}