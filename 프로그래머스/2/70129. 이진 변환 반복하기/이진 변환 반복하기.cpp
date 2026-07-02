#include <string>
#include <vector>

using namespace std;

int rmvZeroCnt;

string splitZero(string& s){
    
    string temp ="";
    
    for(auto a : s){
        if(a == '1'){
            temp += '1';
        }
        else{
            rmvZeroCnt++;
        }
    }
    
    return temp;
}

vector<int> solution(string s) {
    vector<int> answer;
    
    int convCnt = 0;
    rmvZeroCnt = 0;
   
    while( s != "1"){
        convCnt++;
        
        //0 제거
        s = splitZero(s);
        int len = s.length();
        //제거한 길이를 이진수로 표현
        vector<int> conv;
        while(len != 0){
            conv.push_back(len%2);
            len /= 2;
        }
        
        s = "";
        for(int i= conv.size()-1; i>=0; i--){
            s += (conv[i] == 1 ? "1" : "0");
        }
    }

    answer.push_back(convCnt);
    answer.push_back(rmvZeroCnt);
    
    return answer;
}