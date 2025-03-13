#include <iostream>
#include <string>
#include <vector>
using namespace std;

int mappingArr[26];       // 'A'~'Z'에 해당하는 숫자 매핑, 미할당은 -1로 초기화
bool used[10] = { false }; // 0~9 숫자 사용 여부
vector<int> letters;      // 입력된 문자열에 등장하는 문자(인덱스: 'A'-'Z')만 저장
vector<string> token;     // 세 단어 저장
bool possible = false;

void check() {
    int a = 0, b = 0, c = 0;
    int cnt = 1;
    // token[0] 처리
    for (int i = token[0].size() - 1; i >= 0; i--) {
        int idx = token[0][i] - 'A';
        a += cnt * mappingArr[idx];
        cnt *= 10;
    }
    cnt = 1;
    // token[1] 처리
    for (int i = token[1].size() - 1; i >= 0; i--) {
        int idx = token[1][i] - 'A';
        b += cnt * mappingArr[idx];
        cnt *= 10;
    }
    cnt = 1;
    // token[2] 처리
    for (int i = token[2].size() - 1; i >= 0; i--) {
        int idx = token[2][i] - 'A';
        c += cnt * mappingArr[idx];
        cnt *= 10;
    }
    if (a + b == c)
        possible = true;
}

void dfs(int idx) {
    if (possible) return;
    if (idx == letters.size()) {
        check();
        return;
    }
    for (int d = 0; d <= 9; d++) {
        if (used[d]) continue;
        used[d] = true;
        mappingArr[letters[idx]] = d;
        dfs(idx + 1);
        used[d] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string word1, word2, word3;
    cin >> word1 >> word2 >> word3;
    token.push_back(word1);
    token.push_back(word2);
    token.push_back(word3);

    // mappingArr를 -1로 초기화
    for (int i = 0; i < 26; i++) {
        mappingArr[i] = -1;
    }
    // 등장한 문자만 기록 (letters에는 'A'-'Z'에 대한 인덱스 저장)
    bool exist[26] = { false };
    for (auto &word : token) {
        for (char ch : word) {
            int idx = ch - 'A';
            if (!exist[idx]) {
                exist[idx] = true;
                letters.push_back(idx);
            }
        }
    }
    
    dfs(0);
    
    cout << (possible ? "YES" : "NO") << "\n";
    return 0;
}
