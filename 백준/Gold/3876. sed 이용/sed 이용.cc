#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

string applyRule(const string& str, const string& alpha, const string& beta) {
    string result = "";
    int i = 0;
    while (i < str.size()) {
        if (i + alpha.size() <= str.size() && str.substr(i, alpha.size()) == alpha) {
            result += beta;
            i += alpha.size();
        } else {
            result += str[i];
            i++;
        }
    }
    return result;
}

bool solve(int n) {
    vector<pair<string, string>> rules(n);
    for (int i = 0; i < n; i++) {
        cin >> rules[i].first >> rules[i].second;
    }
    
    string start, target;
    cin >> start >> target;
    
    queue<pair<string, int>> q;
    set<string> visited;  // 중복 방문 방지를 위한 집합
    
    q.push({start, 0});
    visited.insert(start);
    
    while (!q.empty()) {
        string now = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if (now == target) {
            cout << cnt << "\n";
            return true;
        }
        
        for (const auto& rule : rules) {
            string next = applyRule(now, rule.first, rule.second);
            
            if (next != now && next.size() <= target.size() && visited.find(next) == visited.end()) {
                q.push({next, cnt + 1});
                visited.insert(next);
            }
        }
    }
    
    cout << "-1\n";  // 변환 불가능
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;  // n이 0이면 종료
        
        solve(n);
    }
    
    return 0;
}