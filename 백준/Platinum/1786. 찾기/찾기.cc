#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> makePI(const string& pattern) {
    int m = pattern.size();
    vector<int> PI(m, 0);
    int k = 0;

    for (int i = 1; i < m; i++) {
        while (k > 0 && pattern[k] != pattern[i])
            k = PI[k - 1];
        if (pattern[k] == pattern[i])
            k++;
        PI[i] = k;
    }

    return PI;
}

void KMP(const string& text, const string& pattern) {
    int n = text.size();
    int m = pattern.size();
    vector<int> PI = makePI(pattern);
    int k = 0;

    vector<int> result;

    for (int i = 0; i < n; i++) {
        while (k > 0 && pattern[k] != text[i])
            k = PI[k - 1];
        if (pattern[k] == text[i])
            k++;
        if (k == m) {
            result.push_back(i - m + 1);
            k = PI[k - 1];
        }
    }

    cout << result.size() << "\n";
    for (int idx : result) {
        cout << idx + 1 << " "; 
    }
    cout << "\n";
}

int main() {
    string text, pattern;

    getline(cin, text);
    getline(cin, pattern);

    KMP(text, pattern);

    return 0;
}
