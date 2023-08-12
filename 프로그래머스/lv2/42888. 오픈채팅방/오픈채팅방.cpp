#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    map<string,string> m;
    vector<vector<string>> seq;
    
    //seq 실행 목록 저장


        for(auto r: record){
            stringstream ss;
            ss.str(r);
            string enter,id,name;
            ss >> enter >> id >> name;
            
            vector<string> sol;
            sol.push_back(enter);
            sol.push_back(id);
            sol.push_back(name);
            seq.push_back(sol);
            
            if(enter == "Enter" || enter == "Change"){
                m[id] = name;
            }


        }
    //출력
    for(int i=0; i<seq.size(); i++){
        if(seq[i][0] == "Enter"){
            answer.push_back(m[seq[i][1]] + "님이 들어왔습니다.");

        }
        else if(seq[i][0] == "Leave"){
            answer.push_back(m[seq[i][1]] + "님이 나갔습니다.");

        }
    }

    
    return answer;
}