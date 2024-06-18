#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

bool visited[10];
string s;
int totalLength;
int findSeq;
int seq;
string ans;


void dfs(int idx,string make) {
    if (idx == totalLength) {
        seq += 1;
        if (seq == findSeq) {
            ans = make;
        }

        return;
    }

    for (int i = 0; i < totalLength; i++) {
        if (!visited[i]) {
            visited[i] = true;
            make += s[i];
            dfs(idx + 1, make);
            make.pop_back();
            visited[i] = false;
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (1) {

        cin >> s >> findSeq;
        totalLength = s.length();

        seq = 0;
        
        memset(visited, false, sizeof(visited));

        if (cin.eof()) {
            break;
        }


        ans = "No permutation";

        dfs(0, "");

        cout << s << " " << findSeq << " = " << ans << '\n';

 


    }

    
    return 0;
}