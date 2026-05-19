#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    
    
    //칫솔 한개 판매 -> 100 원
    //enroll 조직참여한 사람들 순서로 이름
    //referral enroll의 i번째로 참여시킨 사람 이름 , - 면 위에가 센터
    
    //어느 사람 판매 -> 10% 수익빼고 자기가 가짐 -> (1원이상) 부모에게 10% 전파 -> '-' 나올때까지 반복
    
    map<string,int> nameToNum;

    int sellSize = seller.size();
    int n = enroll.size();
    answer.resize(n);
    for(int i=0; i<n; i++){
        nameToNum[enroll[i]] = i;
    }
    
    for(int i=0; i<sellSize; i++){
        
        if(amount[i] == 0) continue;
        int val = amount[i] * 100;
        
        string now = seller[i];
        
        while(now != "-"){
            
            int parentEarn = val * 0.1;
            int myEarn = val - parentEarn;
            
            //cout << "parentEarn : " << parentEarn <<'\n';
            
            //자기가 번 값 추가
            answer[nameToNum[now]] += myEarn;
            val = parentEarn;
            
            if(parentEarn == 0) break;
            
            now = referral[nameToNum[now]];
            
            //cout <<"next:" << now <<'\n';
            
        }
        
    }
    
    return answer;
}