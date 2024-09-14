#include <iostream>
#include <string>

using namespace std;

int main() {
    unsigned long long low = 0, high = 1;
    int read_count = 0;
    const int MAX_READS = 120; // 최대 읽기 횟수 설정

    // 지수 탐색으로 상한선 찾기
    while (true) {
        cout << "buf[" << high << "]" << endl;
        cout.flush();
        read_count++;

        string response;
        cin >> response;

        // 응답 처리
        if (response == "0") {
            // 0을 찾았으므로 상한선을 찾음
            break;
        }
        else if (response == "Segmentation") {
            // 세그멘테이션 폴트 발생 시 종료
            return 0;
        }
        else if (response == "Too") {
            // 최대 읽기 횟수 초과 시 종료
            return 0;
        }
        else {
            // 0이 아닌 값을 찾았으므로 low를 업데이트
            low = high + 1;
            high *= 2;
            if (read_count >= MAX_READS) break;
        }
    }

    // 이분 탐색으로 정확한 N 찾기
    while (low < high && read_count < MAX_READS) {
        unsigned long long mid = low + (high - low) / 2;
        cout << "buf[" << mid << "]" << endl;
        cout.flush();
        read_count++;

        string response;
        cin >> response;

        // 응답 처리
        if (response == "0") {
            // mid 위치에서 0을 찾았으므로 high를 업데이트
            high = mid;
        }
        else if (response == "Segmentation") {
            // 세그멘테이션 폴트 발생 시 종료
            return 0;
        }
        else if (response == "Too") {
            // 최대 읽기 횟수 초과 시 종료
            return 0;
        }
        else {
            // 0이 아닌 값을 찾았으므로 low를 업데이트
            low = mid + 1;
        }
    }

    // 결과 출력
    cout << "strlen(buf) = " << low << endl;
    cout.flush();

    return 0;
}
