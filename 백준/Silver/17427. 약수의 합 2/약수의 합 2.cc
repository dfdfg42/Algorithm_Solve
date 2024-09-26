#include <iostream>

using namespace std;

int main(){
    int N; // N을 입력받는 변수
    long long ans = 0; // 정답을 저장할 변수, long long을 쓴 이유는 값이 매우 커질 수 있기 때문
    cin >> N; // 사용자에게 N을 입력받음
    
    for(int i = 1; i <= N; i++){ // 1부터 N까지 반복
        ans += (N / i) * i; // N을 i로 나눈 몫(N/i)만큼 i를 더해줌
    }
    
    cout << ans << "\n"; // 결과 출력
    return 0;
}
