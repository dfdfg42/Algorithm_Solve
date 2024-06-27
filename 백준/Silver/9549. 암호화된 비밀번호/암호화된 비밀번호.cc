#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <unordered_map>

using namespace std;

bool is_anagram(unordered_map<char, int>& freq_ori, unordered_map<char, int>& freq_win) {
    for (auto& pair : freq_ori) {
        if (freq_win[pair.first] != pair.second) {
            return false;
        }
    }
    return true;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        string encry, ori;
        cin >> encry >> ori;

        bool found = false;
        unordered_map<char, int> orimap;
        for(char c : ori) {
            orimap[c]++;
        }

        unordered_map<char, int> freq_win;
        for (int i = 0; i < ori.length(); i++) {
            freq_win[encry[i]]++;
        }

        if (is_anagram(orimap, freq_win)) {
            found = true;
        }

        // 슬라이딩 윈도우를 사용해 부분 문자열을 검사
        for (int i = ori.length(); i < encry.length() && !found; i++) {
            freq_win[encry[i]]++;
            freq_win[encry[i - ori.length()]]--;

            if (is_anagram(orimap, freq_win)) {
                found = true;
                break;
            }
        }

        if (found) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
