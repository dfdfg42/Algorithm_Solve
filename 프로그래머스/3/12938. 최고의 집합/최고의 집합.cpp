#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    int mod = s/n;
    if(n>s) {
        answer.push_back(-1);
        return answer;
    }
    
    for(int i=0; i<n; i++){
        
        answer.push_back(mod);
        
    }
    
    int ansSize = answer.size();
    int last = s%n;
    
    int idx = 0;
    while(last > 0){
        
        answer[idx] ++;
        
        
        idx = (idx +1 )% ansSize;
        last--;
    }
    
    sort(answer.begin(),answer.end());
    
    
    return answer;
}