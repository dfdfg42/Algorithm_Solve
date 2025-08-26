#include <bits/stdc++.h>
using namespace std;

struct board {
    int win, draw, lose;
};

vector<board> need(6), cur(6);
vector<pair<int, int>> games;
bool possible;

bool quick_check() {
    int sumW = 0, sumD = 0, sumL = 0;
    for (int i = 0; i < 6; ++i) {
        int s = need[i].win + need[i].draw + need[i].lose;
        if (s != 5) return false;               
        sumW += need[i].win;
        sumD += need[i].draw;
        sumL += need[i].lose;
    }
    if (sumW != sumL) return false;            
    if (sumD % 2 != 0) return false;           
    return true;
}

void dfs(int idx) {
    if (possible) return;           
    if (idx == (int)games.size()) {  
        possible = true;
        return;
    }

    auto [a, b] = games[idx];

    // a 승, b 패
    if (cur[a].win + 1 <= need[a].win && cur[b].lose + 1 <= need[b].lose) {
        cur[a].win++; cur[b].lose++;
        dfs(idx + 1);
        cur[a].win--; cur[b].lose--;
    }

    // 무승부
    if (cur[a].draw + 1 <= need[a].draw && cur[b].draw + 1 <= need[b].draw) {
        cur[a].draw++; cur[b].draw++;
        dfs(idx + 1);
        cur[a].draw--; cur[b].draw--;
    }

    // a 패, b 승
    if (cur[a].lose + 1 <= need[a].lose && cur[b].win + 1 <= need[b].win) {
        cur[a].lose++; cur[b].win++;
        dfs(idx + 1);
        cur[a].lose--; cur[b].win--;
    }
}

void solve_one() {
    for (int i = 0; i < 6; ++i) {
        cin >> need[i].win >> need[i].draw >> need[i].lose;
        cur[i] = { 0,0,0 };
    }

    if (!quick_check()) { cout << 0 << ' '; return; }

    games.clear();
    for (int i = 0; i < 6; ++i)
        for (int j = i + 1; j < 6; ++j)
            games.emplace_back(i, j);

    possible = false;
    dfs(0);
    cout << (possible ? 1 : 0) << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    for (int t = 0; t < 4; ++t) {
        solve_one();
   
    }
    cout << '\n';
    return 0;
}
