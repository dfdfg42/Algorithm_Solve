#include <string>
#include <vector>
#include <set>

using namespace std;

//dfs 로 모든 조합을 살펴보고
//이름을 비교하는 함수도 만들어야함


bool nameCmp(string user, string banned){
    
    if(user.length() != banned.length()){
        return false;
    }else{
        for(int i=0; i<user.length(); ++i){
            if(banned[i] != '*' && user[i] != banned[i]){
                return false;
            }
        }
    }
    
    return true;
}

void dfs(vector<string>& user_id, vector<string>& banned_id, vector<bool>& visited, set<set<string>>& result, set<string>& currentSet, int index) {
    if (index == banned_id.size()) {
        result.insert(currentSet);
        return;
    }
    for (int i = 0; i < user_id.size(); ++i) {
        if (!visited[i] && nameCmp(user_id[i], banned_id[index])) {
            visited[i] = true;
            currentSet.insert(user_id[i]);
            dfs(user_id, banned_id, visited, result, currentSet, index + 1);
            currentSet.erase(user_id[i]);
            visited[i] = false;
        }
    }
}


int solution(vector<string> user_id, vector<string> banned_id) {
    
    set<set<string>> result;
    set<string> currentSet;
    vector<bool> visited(user_id.size(), false);
    
     dfs(user_id, banned_id, visited, result, currentSet, 0);

    return result.size();
}