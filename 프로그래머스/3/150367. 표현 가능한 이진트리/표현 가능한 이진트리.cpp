#include <string>
#include <vector>

using namespace std;

bool can(string& target, int left, int right) {
    if (left >= right) {
        return true;
    }

    int mid = (left + right) / 2;

    // 현재 루트가 0이면,
    // 왼쪽 서브트리 / 오른쪽 서브트리 안에 1이 있으면 안 됨
    if (target[mid] == '0') {
        for (int i = left; i <= right; i++) {
            if (target[i] == '1') {
                return false;
            }
        }
    }

    return can(target, left, mid - 1) &&
           can(target, mid + 1, right);
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    
    //101 이 안됨
    //만들어지는 모든 이진수가 중앙이 1이고 대칭인 형태가 되어야함
    //010 or 111 
    
    // -> 홀수개로 앞에 0 패딩을 추가 한 후에
    // -> 가운데 에서 부터 양 옆으로 분할 정복으로 가운데에 0인지 확인
    
    for(auto n : numbers){
        
        //이진수로 바꿔줘야함
        string target = "";
        while(n > 0){
            
            target = char('0' + (n % 2)) + target;
            n /= 2;
            
            
        }

        int target_len = target.length();
        
        //짝수면 홀수개 맞춰줌
        int fullLen = 1;
        while (fullLen < target.size()) {
            fullLen = fullLen * 2 + 1;
        }
        target = string(fullLen - target.size(), '0') + target;
        
        answer.push_back(can(target, 0, fullLen - 1) ? 1 : 0);
        
    }
    
    
    return answer;
}