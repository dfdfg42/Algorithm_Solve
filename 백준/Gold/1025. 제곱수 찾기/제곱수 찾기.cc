#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int n, m;
vector<vector<char>> board;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    board.resize(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++ ) {
            board[i][j] = s[j];
        }
    }

    int rGap;
    int cGap;
    int ans = -1;

    for (int t = 0; t < n; t++) {
        for (int f = 0; f < m; f++) {

            for (int i = -n; i < n; i++) {
                rGap = i;
                for (int j = -m; j < m; j++) {
                    cGap = j;

                    int nextR = t;
                    int nextC = f;
                    string temp = "";

                    if (rGap == 0 && cGap == 0) {
                        temp += board[t][f];
                        if ((int)sqrt(stoi(temp)) * (int)sqrt(stoi(temp)) == stoi(temp)) {
                            ans = max(ans, stoi(temp));
                        }
                        continue;
                    }

   
                    while (nextR >= 0 && nextR < n && nextC >= 0 && nextC < m) {
                        temp += board[nextR][nextC];

                        if ((int)sqrt(stoi(temp)) * (int)sqrt(stoi(temp)) == stoi(temp)) {
                            ans = max(ans, stoi(temp));
                        }

                        nextR += rGap;
                        nextC += cGap;
                    }


                    

                }
            }
        }
    }
    
    cout << ans << '\n';
    
    return 0;
}