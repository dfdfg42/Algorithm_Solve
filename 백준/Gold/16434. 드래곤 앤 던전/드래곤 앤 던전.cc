#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct room {
    int t;
    long long a;
    long long h;
};

vector<room> rooms;
int n;
long long Hatk;

bool runDungeon(long long maxHealth, long long curAtk) {
    long long curHealth = maxHealth;

    for (int i = 0; i < rooms.size(); i++) {
        if (rooms[i].t == 1) {
            long long monsterHealth = rooms[i].h;
            long long monsterAtk = rooms[i].a;

            long long roundsToKillMonster = (monsterHealth + curAtk - 1) / curAtk;
            long long roundsToSurvive = (curHealth + monsterAtk - 1) / monsterAtk;

            if (roundsToSurvive < roundsToKillMonster) {
                return false;
            }

            curHealth -= (roundsToKillMonster - 1) * monsterAtk;

        } else if (rooms[i].t == 2) {
            curAtk += rooms[i].a;
            curHealth = min(maxHealth, curHealth + rooms[i].h);
        }
    }

    return true;
}

int main() {
    cin >> n >> Hatk;
    rooms.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> rooms[i].t >> rooms[i].a >> rooms[i].h;
    }

    long long left = 1;
    long long right = 1e18;  // 최대 값을 매우 크게 설정
    long long result = right;

    while (left <= right) {
        long long mid = (left + right) / 2;

        if (runDungeon(mid, Hatk)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << result << '\n';

    return 0;
}
