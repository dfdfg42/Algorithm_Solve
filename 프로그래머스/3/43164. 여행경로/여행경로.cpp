#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<string, vector<pair<string, bool>>> way;
string priorRoute;
int ticketsSize;
vector<string> answer;

void dfs(string now, int usedTicket, string route , vector<string>& vRoute){
    
    if(usedTicket == ticketsSize){
        //route 가 사전순 앞서면 갱신
        if(priorRoute == ""){
            priorRoute = route;
            answer = vRoute;
        }
        else if(route < priorRoute){
            priorRoute = route;
            answer = vRoute;
        }
        return;
    }
    
    for(auto& w : way[now]){
        
        if(w.second == true){
            continue;
        }else{
            w.second = true;
            vRoute.push_back(w.first);
            string tempRoute = route + w.first;
            dfs(w.first, usedTicket+1 ,tempRoute, vRoute);
            vRoute.pop_back();
            w.second = false;
        }
        
        
    }
    
    return;
}

vector<string> solution(vector<vector<string>> tickets) {

    ticketsSize = tickets.size();
    priorRoute = "";
    
    for(auto t : tickets){
        way[t[0]].push_back({t[1],false});
    }
    
    vector<string> temp;
    temp.push_back("ICN");
    dfs("ICN",0,"",temp);
    
    //모든 항공권을 사용해야함
    //-> ICN 부터 시작해서 항공권의 사용순서
    
    //ICN 으로 시작하는게 여러개 일 수 있음 
    //-> 시작이 여러개
    
    //모든 항공권의 사용확인 -> 개수? , map
    //그래프를 만드는 방법 , 출발지 -> 목적지
    
    return answer;
}