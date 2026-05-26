#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int convInt(string time){
    
    int h = stoi(time.substr(0,2));
    int m = stoi(time.substr(3,2));
    
    return h*60 + m;

}

string convStr(int time){
    
    string temp = "";
    
    string h = to_string(time / 60);
    if(h.length() == 1){
        temp +="0";
    }
    temp += h;
    temp +=":";
    
    string m = to_string(time % 60);
    
    if(m.length()== 1){
        temp += "0";
    }
    
    temp += m;
    
    return temp;
    
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    
    //버스의 총 운행 중에 가장 마지막 시간, 
    // 마지막 시간의 크루가 전부 탈경우 마지막 운행에 타는 크루의 가장 늦는 시간보다 1분 빨리 올 것
    
    //대기 큐로 만들고
    // 운행 시간마다 태우면서 
    // 가장 늦게 탑승한 승객의 시간을 추적
    
    //가장 늦게 탑승한 시간 -1 이 정답
    
    //모든 타임 변환 -> 큐에 넣음
    //09:00부터 버스의 탑승가능까지 대기열에서 뽑아서 넣음
    vector<int> wait;
    queue<int> waitQ;
    
    for(int i=0; i<timetable.size(); i++){
        int conv = convInt(timetable[i]);
        wait.push_back(conv);
    }
    sort(wait.begin(),wait.end());
    
    for(auto w : wait){
        cout << w << ' ' ;
        waitQ.push(w);
    }
    cout <<'\n';
    
    int lastBoarding = 0;
    int nowTime = 540;
    bool needSteal = false;
    for(int i=0; i<n; i++){
        
        int boarding = 0;
        while(!waitQ.empty() && nowTime >= waitQ.front() && boarding < m ){
            
            lastBoarding = waitQ.front();
            
            cout << "waitQfront : " << waitQ.front() <<'\n';
            
            waitQ.pop();
            boarding++;
            
            cout << "nowTime : " << nowTime <<'\n';
            cout << "boarding : " << boarding <<'\n'; 
            cout << "lastBoarding : " << lastBoarding <<'\n';
            
            needSteal = true;
            
        }
        
        if(boarding < m){
            lastBoarding = nowTime;
            needSteal = false;
        }
        
        nowTime += t;
    }
    
    //마지막탑승이 출발 전 -> 훔칠필요없으면 그냥 탐
    if(lastBoarding < 540 && !needSteal){
        cout << 1 <<'\n';
        answer = convStr(540);
    }
    else if (lastBoarding < 540 && needSteal){
        cout << 2 <<'\n';
        answer = convStr(lastBoarding-1);
    }
    else if(needSteal){
        cout << 3 <<'\n';
        answer = convStr(lastBoarding-1);
    }else{
        cout << 4 <<'\n';
        answer = convStr(lastBoarding);
    }
    

    return answer;
}