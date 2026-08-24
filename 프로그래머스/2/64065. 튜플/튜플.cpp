#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    unordered_map <int,int> cnt;

    int num = 0;
    bool read = false;
    for(char c : s){
        
        if( '0' <= c && c<='9'){
            num = num*10 + (c-'0');
            read = true;
        }
        else{
            if(read){
                cnt[num]++;
                num = 0;
                read = false;
            }
            
            
        }
        
    }
    
    vector<pair<int,int>> v;
    
    for(auto [num,count] : cnt){
        v.push_back({count,num});
    }
    
    sort(v.begin(),v.end(), greater<>());
    
    for(auto [count ,num] : v){
        answer.push_back(num);
    }
    
    return answer;
}