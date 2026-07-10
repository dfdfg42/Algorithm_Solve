#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>
#include <iostream>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    map<int,int> m;
    for(auto a : tangerine){
        m[a]++;
    }
    
    vector<int> v;
    for(auto a : m){
        v.push_back(a.second);
    }
    
    sort(v.begin(),v.end(),greater<>());
    // for(auto a : v){
    //     cout << a <<' ' ;
    // }
    
    int sum = 0;
    
    for(int i=0; i<v.size(); i++){
        sum += v[i];
        if(sum >= k){
            answer = ++i;
            break;
        }
    }
    
    
    return answer;
}