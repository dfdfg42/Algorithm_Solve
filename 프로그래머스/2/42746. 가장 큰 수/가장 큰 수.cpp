#include <string>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;



bool cmp(int a, int b) {
    string as = to_string(a);
    string bs = to_string(b);

    return as + bs > bs + as;
}


string solution(vector<int> numbers) {
    
    sort(numbers.begin(), numbers.end(),cmp);
    // 배열의 첫 번째 요소가 0이면 모든 요소가 0임
    if (numbers[0] == 0) {
        return "0";
    }
    
    string answer = "";
    
    for(int i : numbers){
        answer += to_string(i);
    }
    return answer;
}