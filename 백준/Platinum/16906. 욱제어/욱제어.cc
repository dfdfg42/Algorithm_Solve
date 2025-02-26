#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int ROOT = 1;
int unused = 2;
// 문제 조건: 단어 길이의 총합 <= 1000이므로, 노드 개수는 최대 약 1001개 정도.
// (여기서는 여유 있게 큰 배열을 사용)
const int MX = 10000 * 500 + 5;
bool chk[MX];     // 해당 노드가 단어의 끝(terminal)으로 할당되었는지 여부
int nxt[MX][2];   // 각 노드의 0, 1 자식 (없으면 -1)

// 트라이 초기화: 모든 nxt[node][bit]를 -1, chk[node]는 false로 초기화
void initTrie() {
    for (int i = 0; i < MX; i++) {
        nxt[i][0] = nxt[i][1] = -1;
        chk[i] = false;
    }
}

int n;
vector<int> lengths;  // 각 단어의 길이
vector<string> ans;   // 할당한 단어들을 저장

// assignWord : 단어 idx를, 트라이의 node에서 시작하여 depth(현재까지 선택한 비트 수)부터 DFS로 candidate를 찾음.
// cur는 현재까지 구성한 후보 문자열입니다.
bool assignWord(int idx, int node, int depth, string& cur) {
    // target 길이에 도달하면 후보 완성
    if (depth == lengths[idx]) {
        // 이미 단어의 끝으로 쓰였거나 자식이 있으면 안 됨 (리프가 아니면 접두어가 될 위험 있음)
        if (chk[node] || nxt[node][0] != -1 || nxt[node][1] != -1)
            return false;
        chk[node] = true;
        ans[idx] = cur;
        return true;
    }

    if (chk[node]) return false;

    for (int bit = 0; bit < 2; bit++) {
        int nextNode = nxt[node][bit];
        bool created = false;
        if (nextNode == -1) {
            nextNode = unused++;
            nxt[node][bit] = nextNode;
            created = true;
        }
        cur.push_back('0' + bit);
        if (assignWord(idx, nextNode, depth + 1, cur))
            return true; // candidate 발견 시 즉시 반환 (상위 호출에서는 더 이상 pop_back()하지 않음)
        cur.pop_back();  // 이번 분기는 실패했으므로 push한 비트를 되돌림
        if (created)
            nxt[node][bit] = -1; // 새로 만든 노드였으면 원상복구
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    initTrie();

    cin >> n;
    lengths.resize(n);
    ans.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> lengths[i];
    }

    // 각 단어를 순차적으로 할당: 이전에 할당한 단어들은 트라이에 terminal로 남아 있으므로,
    // 후속 단어들은 그들과 접두사 관계가 없도록 candidate를 찾게 됩니다.
    for (int i = 0; i < n; i++) {
        string cur = "";
        if (!assignWord(i, ROOT, 0, cur)) {
            cout << -1 << "\n";
            return 0;
        }
    }

    cout << 1 << "\n";
    for (auto& s : ans)
        cout << s << "\n";

    return 0;
}
