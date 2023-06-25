#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int arr[10001] = {
        0,
    }; // 좌표의 길이

    int N; // 테스트 케이스
    cin >> N;
    int a, b;

    for (int i = 0; i < N; i++) { // 입력된 작대기만큼 배열 활성화
        cin >> a >> b;
        for (int j = a; j < b; j++) { // a 에서 b 범위에 신경쓸것
            arr[j] = 1;
        }
    }

    int cnt = 0;
    for (int k = 1; k <= 10001; k++) { // 작대기 길이 세주기

        if (arr[k] == 1) {
            cnt++;
        }
    }
    cout << cnt;
}