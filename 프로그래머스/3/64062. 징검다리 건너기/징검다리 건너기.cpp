#include <string>
#include <vector>
#include <iostream>

using namespace std;

//val 만큼 이동했을때 연속된 0이 k개 이상인가
bool zeroCount(int val , vector<int>& stones , int k){
    
    int seq = 0;
    //cout << "val : " << val << '\n';
    for(int i=0; i<stones.size(); i++){
        if(stones[i] <= val){
            //cout << i << ' ';
            seq++;
            if(seq >= k ) return false;
        }else{
            //cout <<'\n';
            seq = 0;
        }
    }
    
    
    return true;
}

int solution(vector<int> stones, int k) {

    int answer = 0;
    //stones 길이 200'000
    // 값 2억
    
    //연속된 0이 k개가 되며 안됨
    
    int l = 0; 
    int r = 200'000'000;
    
    while(l<=r){
        int mid = (l+r)/2;
        
        bool can = zeroCount(mid,stones,k);
        //cout <<'\n';
        if(can){
            l = mid +1;
        }else{
            answer = mid;
            r = mid -1;
        }
    }
    
    

    return answer;
}