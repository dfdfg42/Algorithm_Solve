#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, L, f;
        cin >> n >> L >> f;

        // 단어 입력
        vector<string> words(n);
        for (int j = 0; j < n; j++) {
            cin >> words[j];
        }

        int ans = 0;
        int mAns = 0;


        vector<bool> visited(n, false);

        for (int p = 0; p < n; p++) {
            if (visited[p]) continue;

            visited[p] = true;
            string now = words[p];
            string lyme = now.substr(now.size() - f, f);

            for (int x = 0; x < n; x++) {
                if (x == p || visited[x]) continue;

                string tempS = words[x].substr(words[x].size() - f, f);
                if (lyme == tempS) {
                    ans++;
                    visited[x] = true;
                    break;
                }
            }
        }

        mAns = max(mAns, ans);

        cout << mAns << '\n';
    }

    return 0;
}
