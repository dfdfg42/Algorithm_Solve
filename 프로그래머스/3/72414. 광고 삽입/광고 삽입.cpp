#include <string>
#include <vector>
#include <iostream>

using namespace std;

typedef long long ll;

vector<ll> timeline;

//시간은 초단위로 변환
int timeToSec(string s){
    //02:03:55
    int h = stoi(s.substr(0,2)) * 60 * 60;
    int m = stoi(s.substr(3,2)) * 60;
    int sec = stoi(s.substr(6,2));
    
    return h + m + sec;
}

string secToString(int time){
    
    string temp = "";
    
    int h = time / 3600;
    
    if(h < 10){
        temp += "0";
    }
    temp+= to_string(h);
    temp +=":";
    
    int m = (time % 3600) / 60;
    
    if(m<10){
        temp +="0";
    }
    temp += to_string(m);
    temp += ":";
    
    int sec = time % 60;
    
    if(sec < 10){
        temp += "0";
    }
    temp += to_string(sec);
    
    
    return temp;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    timeline.resize(370'000,0);
    int playTime = timeToSec(play_time);
    int advTime = timeToSec(adv_time);
    
    //imos
    //겹치는 개수 n 개 만큼 시청시간 배수
    
    //imos -> 전체 구간 누적 시청시간 구하기
    // -> 브루트포스로 0초부터 끝까지 넣어보기  (누적합으로 구간합 구하기)
    
    for(auto l  : logs){
        //01:30:59-01:53:29
        int t = timeToSec(l.substr(0,8));
        int t2 = timeToSec(l.substr(9,8));
        timeline[t]++;
        timeline[t2]--;
    }
    
    
    for(int i=1 ; i<timeline.size(); i++){
        timeline[i] = timeline[i] + timeline[i-1];
    }
    //누적합
    for(int i=1; i<timeline.size(); i++){
        timeline[i] += timeline[i-1];
    }
    
    
    ll maxViewTime = -1;
    for(int i=0; i<= playTime - advTime; i++){
        ll nowTime = timeline[i + advTime-1] - (i==0 ? 0 : timeline[i-1]) ;
        
        if(nowTime > maxViewTime){
            maxViewTime = nowTime;
            answer = secToString(i);
        }
        
    }
    
    cout <<"maxViewTime:" <<maxViewTime << '\n';
    
    return answer;
}