#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = -1;
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int lenA = A.size();
    int lenB = B.size();
    int idxA = 0;
    int idxB = 0;
    
    int ans = 0;
    
    while(idxB < lenB && idxA < lenA){
        
        while(A[idxA] >= B[idxB] ){
            idxB++;
        }
        
        if(idxB >= lenB) break;
        //B가 승리
        ans++;
        idxA++;
        idxB++;
        
    }
    
    
    return ans;
}