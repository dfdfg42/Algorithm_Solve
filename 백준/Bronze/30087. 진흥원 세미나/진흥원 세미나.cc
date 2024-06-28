#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <unordered_map>

using namespace std;




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    int n;
    cin >> n;

    map<string, string> map;

    map["Algorithm"] = "204";
    map["DataAnalysis"] = "207";
    map["ArtificialIntelligence"] = "302";
    map["CyberSecurity"] = "B101";
    map["Network"] = "303";
    map["Startup"] = "501";
    map["TestStrategy"] = "105";



    vector<string> cnt;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        cnt.push_back(s);

    }
    for (int i = 0; i < cnt.size(); i++) {
        cout << map[cnt[i]] << '\n';
    }

    return 0;
}
