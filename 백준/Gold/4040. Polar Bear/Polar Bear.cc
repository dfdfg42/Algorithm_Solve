#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;


int m, n;

vector<pair<int, int>> cells;
vector<vector<int>> polar;

int findAround(int ring, int cell);
void simulate(int g) {

    for (int p = 0; p < g; p++) {

        //변경을 저장할 임시 벡터
        vector<vector<int>> polarCopy = polar;
        //모든셀 조회
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // 그 주위 살아있는 셀 몇개 인지 조회
                int aroundLiveCells = findAround(i, j);

                if (polar[i][j] == 1) { // 현재 셀이 살아있는 경우
                    if (aroundLiveCells < 2 || aroundLiveCells > 3) {
                        polarCopy[i][j] = 0;
                    }
                }
                else { // 현재 셀이 죽어있는 경우
                    if (aroundLiveCells == 3) {
                        polarCopy[i][j] = 1;
                    }
                }

                //cout << aroundLiveCells << ' ';

            }
        }


        polar = polarCopy;



    }

}

// 주위 셀 조사 함수
int findAround(int ring, int cell) {
    int cellCount = 0;
    int half = n / 2; // 반대편 셀을 찾기 위한 반

    // 링의 이전 링, 현재 링, 다음 링을 탐색 (-1, 0, 1)
    for (int i = -1; i <= 1; i++) { // 링 방향
        for (int j = -1; j <= 1; j++) { // 셀 방향
            if (i == 0 && j == 0) continue; // 자기 자신은 제외
            int nextRing = ring + i;
            int nextCell = (cell + j + n) % n; // 셀 번호는 모듈로 연산으로 순환
            if (nextRing >= 0 && nextRing < m) { // 링 범위 내인지 확인
                if (polar[nextRing][nextCell] == 1) {
                    cellCount++;
                }  
            }
            else {
                // 반대편 셀을 체크
                int oppositeCell = (nextCell + half + n) % n;
                if (polar[ring][oppositeCell] == 1) {
                    cellCount++;
                }
            }
        }
    }

    return cellCount;
}

void resultCells(int testCase) {
    int cellCount = 0;
    pair<int, int> first = { -1, -1 };
    pair<int, int> last = { -1, -1 };

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (polar[i][j] == 1) {
                cellCount++;
                if (first.first == -1) { // 첫 번째 생존 셀 설정
                    first = { i, j };
                }
                last = { i, j }; // 마지막 생존 셀 계속 업데이트
            }
        }
    }

    cout << "Case " << testCase << ": ";
    if (cellCount == 1) {
        cout << cellCount << " " << 0 << " " << 0<< " "
            << last.first << " " << last.second << "\n";
    }
    else if (cellCount > 0) {
        cout << cellCount << " " << first.first << " " << first.second << " "
            << last.first << " " << last.second << "\n";
    }
    else {
        cout << "0 -1 -1 -1 -1\n";
    }
}

int main() {


    int t = 0;
    while (true) {

        cin >> m >> n;
        if (n == 0 && m == 0) {
            return 0;
        }
        t++;
        polar.assign(m ,vector<int>(n,0));

        int k;
        cin >> k;
        cells.clear();
        for (int i = 0; i < k; i++) {
            int ring, cell;
            cin >> ring >> cell;
            cells.push_back({ ring,cell });
            polar[ring][cell] = 1; //살아있음
        }

        int g;
        cin >> g;



        //g 만큼 시뮬레이션 진행
        simulate(g);

    

        //결과 출력
        resultCells(t);
    }
    

    return 0;
}
