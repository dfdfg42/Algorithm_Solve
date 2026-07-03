#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    //연속한 자연수로 표현
    //투포인터
    
    int sum = 0;
    int l = 1;
    for(int r=1; r<=10'000; r++){
        
        while(sum > n && l < r){
            sum -= l++;
            if(sum == n) answer++;
        }
        
        sum += r;
        if(sum == n) answer++;
    }
    
    return answer;
}