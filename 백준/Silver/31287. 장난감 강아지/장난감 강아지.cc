#include <iostream>
#include <string> // 명시적으로 string 헤더 포함

using std::cin;
using std::cout;
using std::string;

int main()
{
    int N, K; // N: 문자열 길이, K: 반복 횟수
    string commands; // 사용자로부터 입력받을 명령어 문자열
    int posX = 0, posY = 0; // 현재 위치를 나타내는 x, y 좌표

    cin.sync_with_stdio(false); // cin, cout의 tie를 해제하여 성능 향상
    cin.tie(nullptr);

    cin >> N >> K;
    cin >> commands;

    // K가 N의 절반보다 큰 경우, K를 N의 절반으로 조정
    if (K > N / 2) {
        K = N / 2;
    }

    // K번 반복
    while (K--) {
        // 문자열 commands를 순회하면서 각 문자에 따라 위치를 업데이트
        for (char direction : commands) {
            switch (direction) {
                case 'U': ++posY; break;
                case 'D': --posY; break;
                case 'L': --posX; break;
                case 'R': ++posX; break;
            }

            // 원점에 도달한 경우, "YES" 출력 후 프로그램 종료
            if (posX == 0 && posY == 0) {
                cout << "YES";
                return 0;
            }
        }
    }

    // K번의 반복 후에도 원점에 도달하지 못한 경우, "NO" 출력
    cout << "NO";
    return 0;
}
