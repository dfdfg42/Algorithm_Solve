#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

unordered_map<char, int> mapping;
vector<pair<char, int>> alphas;
vector<string> token;
unordered_map<char, long long> coef; // 각 문자에 대한 계수(precomputed coefficient)
bool possible;
bool used[10] = { false };

void precomputeCoef() {
    // token[0]와 token[1]는 양의 가중치, token[2]는 음의 가중치
    // 자리수는 가장 왼쪽이 최고 자리이므로, weight = 10^(len - i - 1)
    for (int t = 0; t < 3; t++) {
        int len = token[t].size();
        int sign = (t < 2) ? 1 : -1; // token0, token1: +1, token2: -1
        for (int i = 0; i < len; i++) {
            char ch = token[t][i];
            long long weight = 1;
            for (int j = 0; j < len - i - 1; j++) {
                weight *= 10;
            }
            coef[ch] += sign * weight;
        }
    }
}

void check() {
    long long total = 0;
    // 모든 등장 문자에 대해 mapping값과 미리 구한 계수를 곱해 더함
    for (auto &p : mapping) {
        total += (long long)p.second * coef[p.first];
    }
    if (total == 0)
        possible = true;
}

void dfs(int idx) {
    if (possible) return;
    if (idx == alphas.size()) {
        check();
        return;
    }
    
    for (int i = 0; i <= 9; i++) {
        if (used[i]) continue;
        used[i] = true;
        alphas[idx].second = i;
        mapping[alphas[idx].first] = i;
        dfs(idx + 1);
        used[i] = false;
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
    
    // 등장하는 문자들만 mapping 및 alphas에 저장
    for (auto &word : token) {
        for (char ch : word) {
            if (mapping.find(ch) == mapping.end()) {
                mapping[ch] = -1;
                alphas.push_back({ ch, -1 });
            }
        }
    }
    
    precomputeCoef(); // 각 문자별 계수 전처리

    possible = false;
    dfs(0);
    
    cout << (possible ? "YES" : "NO") << "\n";
    return 0;
}
