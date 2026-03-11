#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <string>

using namespace std;

typedef long long ll;

int N, M, D;
int maxEliminated;

vector<vector<int>> board;
vector<pair<int, int>> enemiesOri;

void gameLoop(vector<int>& archers) {

    int eliminated = 0;


    //적이 살아있는동안 진행
    vector<pair<int, int>> enemies = enemiesOri;
    while (!enemies.empty()) {
        vector<bool> beDelete(enemies.size());
        //궁수의 공격
        //각 궁수마다 적들의 거리구하기
        for (auto a : archers) {

            //거리, 적 인덱스
            vector<pair<int, pair<int,int>>> temp;

            //D 이하인것에서 가장 왼쪽거 잡기
            for (int i = 0; i < enemies.size(); i++) {
                pair<int, int> e = enemies[i];
                int dist = abs((e.first - N)) + abs((e.second - a));
                if(dist<=D)
                temp.push_back({ dist, {e.second,i} });

                
            }
            sort(temp.begin(), temp.end());

            if (!temp.empty()) {

                beDelete[temp[0].second.second] = true;

            }



        }

        for (int i = enemies.size() - 1; i >= 0; i--) {
            if (beDelete[i]) {
                enemies.erase(enemies.begin() + i);
                eliminated++;
            }
        }

        //적이 아래로 이동

        for (int i = enemies.size() - 1; i >= 0; i--) {

            int ny = enemies[i].first + 1;
            if (ny >= N) {
                enemies.erase(enemies.begin() + i);
            }
            else {
                enemies[i].first += 1;
            }


        }

    }


    maxEliminated = max(eliminated, maxEliminated);

}

void dfs(int depth, int index, vector<int>& archers) {
    if (depth == 3) {

        gameLoop(archers);


        return;
    }

    for (int i = index+1; i < M; i++) {

        archers.push_back(i);
        dfs(depth+1,i , archers);
        archers.pop_back();

    }
}





int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    maxEliminated = 0;
    cin >> N >> M >> D;
    board.resize(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) {
                enemiesOri.push_back({ i,j });
            }
        }
    }
    
    // 궁수의 위치 3개 반환
    vector<int> temp;
    dfs(0,-1,temp);

    cout << maxEliminated << '\n';


    return 0;
}