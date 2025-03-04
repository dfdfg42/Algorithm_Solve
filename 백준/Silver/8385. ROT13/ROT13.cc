#include <bits/stdc++.h>
using namespace std;

string rot13(const string &s) {
    string ret;
    ret.reserve(s.size());
    for (char ch : s) {
        int x = ch - 'a';
        x = (x + 13) % 26;
        ret.push_back((char)(x + 'a'));
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    unordered_set<string> words;
    words.reserve(n);
    words.max_load_factor(0.7f);

    string s;
    for(int i = 0; i < n; i++){
        cin >> s;
        words.insert(s);
    }

    long long cnt = 0;
 
    for(auto &w : words){
        string r = rot13(w);
        if(words.find(r) != words.end()){
            if(w < r)
                cnt++;
        }
    }

    long long ans = cnt * 2LL;
    cout << ans << "\n";
    return 0;
}
