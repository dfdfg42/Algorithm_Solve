#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int TABLE_SIZE = 100003; 

int getHash(const string& s) {
    unsigned long long hash_val = 0;
    for (char c : s) {
        hash_val = hash_val * 131 + c;
    }
    return hash_val % TABLE_SIZE;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N, M;
        cin >> N >> M;

        vector<vector<string>> hashTable(TABLE_SIZE);

        string str;
        for (int i = 0; i < N; i++) {
            cin >> str;
            int idx = getHash(str);
            hashTable[idx].push_back(str);
        }

        int answer = 0;
        for (int i = 0; i < M; i++) {
            cin >> str;
            int idx = getHash(str);
            for (const auto& s : hashTable[idx]) {
                if (s == str) {
                    answer++;
                    break;
                }
            }
        }

        cout << "#" << t << " " << answer << "\n";
    }

    return 0;
}