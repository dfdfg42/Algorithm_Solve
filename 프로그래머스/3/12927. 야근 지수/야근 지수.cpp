#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <iostream>

using namespace std;

typedef long long ll;

ll solution(int n, vector<int> works) {
    ll answer = 0;
    
    //지수 스케일이기 때문에 각자 가장큰거부터 동일하게 낮추려고 하면됨
    
    priority_queue<int,vector<int>> pq;
    for(int i=0; i<works.size(); i++){
        pq.push(works[i]);
    }
    for(int i=0; i<n; i++){
        
        if(pq.top() == 0) break;
        int now = pq.top() -1;
        pq.pop();
        pq.push(now);
        
    }
    
    while(!pq.empty()){
        //cout << pq.top() <<'\n';
        answer += pow(pq.top(),2);
        pq.pop();
    }
    
    return answer;
}