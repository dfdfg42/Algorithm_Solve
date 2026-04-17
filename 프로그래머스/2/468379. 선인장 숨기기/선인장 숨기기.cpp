#include <string>
#include <vector>
#include <climits>
#include <deque>

using namespace std;

const int INF = INT_MAX;
vector<vector<int>> rain;

vector<int> solution(int m, int n, int h, int w, vector<vector<int>> drops) {
    
    rain.resize(m,vector<int>(n,INF));
    
    for(int i=0; i<drops.size(); i++){
          rain[drops[i][0]][drops[i][1]]  = i+1;
    }
    
    //행의 최솟값 저장
    vector<vector<int>> row_min(m,vector<int>(n-w+1));
    
    for(int i=0; i<m; i++){
        deque<int> dq; //열 인덱스
        for(int j=0; j<n; j++){
            
            while(!dq.empty() &&  rain[i][dq.back()]>= rain[i][j]){
                dq.pop_back();
            }
            
            dq.push_back(j);
            
            if(dq.front() <= j-w){
                dq.pop_front();
            }
            
            if(j>=w-1){
                row_min[i][j - w + 1] = rain[i][dq.front()];
            }
            
            
        }
        
    }
    
    int minVal = -1;
    int ansC = -1;
    int ansR = -1;
    
    for(int c=0; c<n-w+1; c++){
        
        deque<int> dq;
        for(int r =0 ; r<m; r++){
            
            while(!dq.empty() && row_min[dq.back()][c] >= row_min[r][c]){
                dq.pop_back();
            }
            
            dq.push_back(r);
            
            if(dq.front() <= r-h){
                dq.pop_front();
            }
            
            if(r >= h-1){
                int cur = row_min[dq.front()][c];
               if(cur > minVal ||
                  (cur == minVal && (r-h+1) < ansR) ) {
                    minVal = cur;
                    ansR = r - h + 1;
                    ansC = c;
                }
            }
            
            
        }
    }
    
    
    
    vector<int> answer;
    answer.push_back(ansR);
    answer.push_back(ansC);
    return answer;
}