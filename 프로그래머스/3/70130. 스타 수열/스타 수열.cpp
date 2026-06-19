#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <set>;

using namespace std;


int solution(std::vector<int> a) {
    int answer = -1;
    int n = a.size();
    set<int> s;
    map<int,int> m;
    for(int i=0; i<n; i++){
        s.insert(a[i]);
        m[a[i]]++;
    }
    for(auto star : s){
        if(m[star] * 2 <= answer) continue; 
        int cnt = 0;
        bool isConnected = false;
        for(int i=0; i<n; i++){
            
            if(a[i] == star){
                if(i > 0 && a[i-1] != star && isConnected == false ){
                    cnt++;
                    isConnected =false;
                }
                else if(i+1 < n && a[i+1] != star){
                    isConnected = true;
                    cnt++;
                    i++;
                }
            }else{
                isConnected =false;
            }
            
        }
        
        //cout << "star: " << star << ' ' << "cnt : " << cnt <<'\n';
        answer = max(answer,cnt*2);
    }
   
    return answer;
}