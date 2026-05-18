#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int n;

ll solution(vector<int> sequence) {
    ll answer = 0;
    
    n = sequence.size();
    vector<int> startP;
    vector<int> startM;
    
    for(int i=0; i<n; i++){
        startP.push_back(sequence[i] * ( i % 2 == 0 ? 1 : -1));
        startM.push_back(sequence[i] * ( i % 2 == 0 ? -1 : 1));
    }
    
    // 부분수열에 -1, 1 ,-1  ... or 1 ,-1 ,1 을 곱해서 가장 커지는 부분수열
    
    //즉 가장 커지는 부분수열 구하기 
    //누적합이 음수가되면 바로 새롭게 출발
    ll sum = 0;
    // 1로 시작하는 친구
    int l = 0; 
    int r = 0;
    ll tempSum = 0 ;
    while(r != n){
        tempSum += startP[r];
        sum = max(sum,tempSum);
        if(tempSum < 0){
            tempSum = 0;
        }
        
        r++;
    }
    
    answer = sum;
    
    // -1로 시작하는 친구
    r = 0;
    tempSum = 0 ;
    sum = 0;
    while(r != n){
        tempSum += startM[r];
        sum = max(sum,tempSum);
        if(tempSum < 0){
            tempSum = 0;
        }
        
        r++;
    }
    
    answer = max(answer,sum);
    
    return answer;
}