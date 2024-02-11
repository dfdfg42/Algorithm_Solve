#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <set>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N; // N 값을 입력받음
    map<int, int> cardMap;

    for (int i = 0; i < N; i++) {
        int input;
        cin >> input;
        cardMap[input]++; // map에 카드의 빈도를 증가
    }

    int M;
    cin >> M; // M 값을 입력받음
    vector<int> targets(M); // targets의 크기를 M으로 초기화

    for (int i = 0; i < M; i++) {
        int input;
        cin >> input;

        // cardMap에서 input에 해당하는 빈도수를 찾아 targets에 저장
        if (cardMap.find(input) != cardMap.end()) {
            targets[i] = cardMap[input];
        }
        else {
            targets[i] = 0; // 요소가 없으면 0으로 설정
        }
    }

    // 결과 출력
    for (int i = 0; i < M; i++) {
        cout << targets[i] << " ";
    }

    return 0;
}
