#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    
    int len = topping.size();
    
    vector<int> cnt1(10001);
    vector<int> cnt2(10001);
    
    int g1 = 0;
    int g2 = 0;
    
    for(int i=0; i<topping.size(); i++){
        if(cnt2[topping[i]] == 0) g2++;
        cnt2[topping[i]]++;
    }
    
    for(int cut = 0; cut < topping.size(); cut++){
        
        int target = topping[cut];
        cnt2[target]--;
        if(cnt2[target] == 0) g2--;
        
        if(cnt1[target] == 0) g1++;
        cnt1[target]++;
        
        if(g1 == g2) answer++;
        
    }
    
    return answer;
}