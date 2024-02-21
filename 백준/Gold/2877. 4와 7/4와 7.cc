#include <iostream>
#include <string>
using namespace std;

// 4와 7로 이루어진 수를 구하는 함수
string findKthNumber(int K) {
    string result = "";
    while (K > 0) {
        // K가 홀수라면, 결과에 '4' 추가
        if (K % 2 == 1) {
            result = '4' + result;
        }
        else {
            // K가 짝수라면, 결과에 '7' 추가
            result = '7' + result;
        }
        K = (K - 1) / 2;  // 부모 노드로 이동
    }
    return result;
}

int main() {
    int K;
    cin >> K;
    cout << findKthNumber(K) << endl;
    return 0;
}
