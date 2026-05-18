#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct job{
    
    //작업의 소요시간
    int needTime;
    
    //작업의 요청시간
    int startTime;
    
    //작업 번호
    int jobNum;
    
    bool operator< (const job& other) const {
        
        if(needTime != other.needTime){
            
            return needTime > other.needTime;
            
        }else if(startTime != other.startTime){
            
            return startTime > other.startTime;
        }
        
        return jobNum > other.jobNum;
        
    }


    
};

int solution(vector<vector<int>> jobs) {
    // 반환시간(요청시간 - 작업종료시간) 의 평균
    int answer = 0;
    int sum = 0;
    int n = jobs.size();
    
    
    
    int time = 0;
    vector<vector<job>> jobVec(1001);
    for(int i=0; i<n; i++){
        jobVec[jobs[i][0]].push_back({jobs[i][1],jobs[i][0],i});
    }
    
    
    //우선순위 : 소요시간짧은거 > 요청시간 빠른거 > 작업번호 작은 거
    priority_queue<job,vector<job>> pq;
    
    bool start = false;
    job nowJob;
    int startTime = 0;
    int jobCount = 0;
    while(jobCount < n){
        
        //시간대가 되면 대기큐에 그 작업을 큐에 넣음
        //-> 그 시간에 시작되는 작업을 확인해야함
        if(time < 1001){
                for(auto j : jobVec[time]){
                pq.push(j);
            }
        }

        
        
        if(start ==false && !pq.empty()){
            start =true;
            nowJob = pq.top();
            pq.pop();
            startTime = time;
        }//작업이 종료됬는지 확인
        else if(start && time - startTime >= nowJob.needTime){
            //종료 됬으면 우선순위 가장높은 작업을 넣음
            sum += time - nowJob.startTime;
            jobCount++;
            if(!pq.empty()){
                startTime = time;
                nowJob = pq.top();
                pq.pop();
            }
            else { start = false; }
        }
        
        time++;
        
    }
    
    answer = sum/n;
    
    return answer;
}