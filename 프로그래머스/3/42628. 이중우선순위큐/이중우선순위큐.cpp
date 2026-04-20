#include <string>
#include <vector>
#include <sstream>
#include <queue>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations) {
    
    vector<int> answer;
    
    set<int> cache;
    priority_queue<int,vector<int>> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;
    
    for(string s : operations){
        
        stringstream ss (s);
        string op;
        int val;
        
        ss >> op;
        ss >> val;
        
        //큐에 주어진 숫자 삽입
        if(op == "I"){
            cache.insert(val);
            maxHeap.push(val);
            minHeap.push(val);
        }
        else if(op == "D" && val == 1){
            //큐에서 최댓값 삭제
            while(!maxHeap.empty() && cache.find(maxHeap.top()) == cache.end()){
                 maxHeap.pop();
            }
            if(maxHeap.empty()) continue;
            
            int target = maxHeap.top();
            cache.erase(target);
            maxHeap.pop();
        }
        else if(op == "D" && val == -1){
            while(!minHeap.empty() && cache.find(minHeap.top()) == cache.end()){
                 minHeap.pop();
            }
            if(minHeap.empty()) continue;
            
            int target = minHeap.top();
            cache.erase(target);
            minHeap.pop();
        } 
        
    }
    
    while(!maxHeap.empty() && cache.find(maxHeap.top()) == cache.end()){
        maxHeap.pop();
    
    }
    
    while(!minHeap.empty() && cache.find(minHeap.top()) == cache.end()){
        minHeap.pop();
    }
    
    if(maxHeap.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        answer.push_back(maxHeap.top());
        answer.push_back(minHeap.top());
    }

    
    
    return answer;
}