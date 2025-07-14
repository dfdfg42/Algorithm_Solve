#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int> b){
    return a[1] < b[1];
}

int solution(vector<vector<int>> targets) {
    
    if(targets.empty()){
        return 0;
    }
    sort(targets.begin(),targets.end(),cmp);
    
    int answer = 1;
    int endPos = targets[0][1];
    
    for(auto target : targets){
        if(target[0] < endPos){
            
        }else{
            endPos = target[1];
            answer++;

        }
    }
    

    return answer;
}