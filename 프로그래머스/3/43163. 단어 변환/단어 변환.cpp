#include <string>
#include <vector>
#include <climits>

using namespace std;

string g_target;
vector<string> g_words;
int ans;

bool isOneDiff(string& a , string& b){
    int cnt = 0;
    
    for(int i=0; i<a.length(); i++){
        if(a[i] != b[i]){
            cnt ++;
            if(cnt >1) return false;
        }
    }
    
    if(cnt == 1) return true;
    
    return false;
}

void dfs(string now , int cnt ,vector<bool>& visited){
    
    if(cnt > ans){
        return;
    }
    else if(now == g_target){
        ans = cnt;
        return;
    }
    
    for(int i=0; i<g_words.size(); i++){
        if(!visited[i] && isOneDiff(now,g_words[i])){
            
            visited[i] = true;
            dfs(g_words[i],cnt+1, visited);
            visited[i] = false;
            
            
        }
    }
    
}

int solution(string begin, string target, vector<string> words) {
    g_target = target;
    g_words = words;
    ans = INT_MAX;
    
    //depth 50 까지 가능
    //한글자 차이나면 진입
    //이미 진입한거의 재진입 불가
    vector<bool> visited(words.size());
    dfs(begin,0,visited);
    
    if(ans == INT_MAX) ans = 0;
    return ans;
}