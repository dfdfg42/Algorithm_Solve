#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<bool> visited;
int n;


int solution(vector<int> sticker)
{
    int answer =0;
    n = sticker.size();
    
    if(n == 1 ){
        return sticker[0];
    }
    
    
    //dp 두번 , 0번 인덱스를 고를때 , 안고를때
    vector<int> dp1 (n,0);
    
    dp1[0] = sticker[0];
    dp1[1] = dp1[0];
    
    //0번 인덱스를 골랐을 때
    for(int i=2; i<n-1; i++){
        dp1[i] = max(dp1[i-2] + sticker[i], dp1[i-1]);
    }
    
    dp1[n-1] = dp1[n-2];
    
    //0번 인덱스를 안 골랐을 때
    vector<int> dp2(n,0);
    dp2[1] = sticker[1];
    for(int i=2; i<n; i++){
        dp2[i] = max(dp2[i-2] + sticker[i], dp2[i-1]);
    }
    
    answer = max(dp1[n-1], dp2[n-1]);

    return answer;
}