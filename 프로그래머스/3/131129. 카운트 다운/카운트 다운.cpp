#include <string>
#include <vector>


using namespace std;

const int INF = 987654321;

vector<int> solution(int target) {
    vector<int> answer;
    
    // 최소횟수 ,  싱글 또는 불을 맞춘 횟수 (합)
    
    //target <= 100'000;
    // 점수 1~20 , 트리플 더블 , + 불
    
    //dp[점수] = 점수를 최소횟수로 도달하는 방법  
    
    //{횟수 , 트리플 + 불 사용횟수 }
    vector<pair<int,int>> dp(target+1,{INF,INF});
    
    dp[0] = {0,0};
    
    for(int i=1; i<=target; i++){
        for(int j=1; j<= 20; j++){
            
            int next = j;
            if(i-next >= 0){
                
                if(dp[i].first > dp[i-next].first + 1 ){
                    
                    dp[i].first = dp[i-next].first+1;
                    dp[i].second = dp[i-next].second+1;
                    
                }
                else if(dp[i].first == dp[i-next].first +1 && dp[i].second < dp[i-next].second+1){
                    dp[i].second = dp[i-next].second+1;
                }
                
            }
            next = 2*j;
            if(i- next >= 0){
                if(dp[i].first > dp[i-next].first + 1 ){
                    
                    dp[i].first = dp[i-next].first+1;
                    dp[i].second = dp[i-next].second;
                    
                }
                else if(dp[i].first == dp[i-next].first +1 && dp[i].second < dp[i-next].second){
                    dp[i].second = dp[i-next].second;
                }
            }
            next = 3*j;
            if(i-next >= 0){
                if(dp[i].first > dp[i-next].first + 1 ){
                    
                    dp[i].first = dp[i-next].first+1;
                    dp[i].second = dp[i-next].second;
                    
                }
                else if(dp[i].first == dp[i-next].first +1 && dp[i].second < dp[i-next].second){
                    dp[i].second = dp[i-next].second;
                }
            }
            next = 50;
            if(i-next >= 0){
                if(dp[i].first > dp[i-next].first + 1 ){
                    
                    dp[i].first = dp[i-next].first+1;
                    dp[i].second = dp[i-next].second+1;
                    
                }
                else if(dp[i].first == dp[i-next].first +1 && dp[i].second < dp[i-next].second+1){
                    dp[i].second = dp[i-next].second+1;
                }
            }
        }
    }
    
    answer.push_back(dp[target].first);
    answer.push_back(dp[target].second);
    
    return answer;
}