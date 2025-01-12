#include <iostream>
#include <vector>
#include <climits>
using namespace std;



int a, b;
int n;
vector<vector<bool>> paper;

void fill() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            paper[260 - (b+i)][260 - (a + j)] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;


    paper.resize(260, vector<bool>(260));

    while (n--) {
        cin >> a >> b;
        fill();

    }

    int ans = 0;
    for (int i = 0; i < 260; i++) {
        for (int j = 0; j < 260; j++) {
            if (paper[i][j] == true) ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}
