#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string s) {
    
    
    bool isFirst = true;
    string answer;
    for(int i=0; i<s.length(); i++){
        
        if(s[i] == ' '){
            isFirst = true;
            continue;
        }
        else{
            
            if(isFirst){
                if(isalpha(s[i])){
                    if(islower(s[i])){
                        s[i] -= 32;
                    }
                }
                isFirst = false;
            }
            else if(isalpha(s[i])){
                
                if(isupper(s[i])){
                    s[i] += 32;
                }
                
            }
            
            
        }
        
        
    }
    
    answer = s;

    return answer;
}