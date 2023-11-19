//백준2623 음악프로그램
 
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
int N, M;                    //가수 수, PD 수
int inDeg[1002] = { 0, };    //진입차수(=선행 노드 수)
vector<int> v[1002];
vector<int> ans;             //출력저장벡터
 
int main() {
    cin >> N >> M;
 
    while (M--) {
        int sNum;
        int s1, s2;
        cin >> sNum;
        if (sNum == 0) continue;
        cin >> s1;
        if (sNum == 1) continue;
 
        for (int i = 0; i < sNum-1; i++) {
            cin >> s2;
            v[s1].push_back(s2);
            inDeg[s2]++;
            s1 = s2;
        }
    }
 
    queue<int> q;
 
    for (int i = 1; i <= N; i++) {
        if (inDeg[i] == 0) {
            q.push(i);
        }
    }
 
    while (!q.empty()) {
        int s = q.front();
        q.pop();
        ans.push_back(s);
 
        for (int i = 0; i < v[s].size(); i++) {
            int next = v[s][i];
            inDeg[next]--;
            if (inDeg[next] == 0) {
                q.push(next);
            }
        }
    }
 
    if (ans.size() != N) {
        cout << 0 << endl;
        return 0;
    }
    else {
        for (int i = 0; i < N; i++) {
            cout << ans[i] << endl;
        }
    }
 
    return 0;
}
