#include <string>
#include <vector>
#include <climits>

using namespace std;

int solution(vector<int> a) {
    int n = (int)a.size();
    if (n <= 2) return n; 
    vector<int> leftMin(a.size(), INT_MAX);
    vector<int> rightMin(a.size(), INT_MAX);

    leftMin[0] = a[0];
    for (int i = 1; i < n; ++i) {
        leftMin[i] = min(leftMin[i-1], a[i]);
    }

    rightMin[n-1] = a[n-1];
    for (int i = n-2; i >= 0; --i) {
        rightMin[i] = min(rightMin[i+1], a[i]);
    }
    
    int answer = 0;
    answer += 2; //양끝은 무조건 가능
    for(int i=1; i<a.size()-1; i++){
        if( leftMin[i-1] > a[i] || rightMin[i+1] > a[i]){
            answer++;
        }
    
    }
    
    

    return answer;
}