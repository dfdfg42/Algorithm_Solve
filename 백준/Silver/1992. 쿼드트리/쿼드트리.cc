#include <iostream>
#include <string>
using namespace std;

const int MAX = 64;
int image[MAX][MAX];

string compress(int x, int y, int size) {
    // 현재 영역의 첫 번째 원소를 확인
    int first = image[x][y];
    bool isUnified = true;
    
    // 전체 영역을 순회하며 모든 원소가 같은지 확인
    for (int i = x; i < x + size; ++i) {
        for (int j = y; j < y + size; ++j) {
            if (image[i][j] != first) {
                isUnified = false;
                break;
            }
        }
        if (!isUnified) break;
    }
    
    // 모든 원소가 같다면 해당 원소 반환
    if (isUnified) return to_string(first);
    
    // 그렇지 않다면 4등분하여 재귀적으로 함수 호출
    int newSize = size / 2;
    string upperLeft = compress(x, y, newSize);
    string upperRight = compress(x, y + newSize, newSize);
    string lowerLeft = compress(x + newSize, y, newSize);
    string lowerRight = compress(x + newSize, y + newSize, newSize);
    
    // 4등분한 결과를 괄호로 묶어서 반환
    return "(" + upperLeft + upperRight + lowerLeft + lowerRight + ")";
}

int main() {
    int N;
    cin >> N;
    
    for (int i = 0; i < N; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < N; ++j) {
            image[i][j] = row[j] - '0';
        }
    }
    
    cout << compress(0, 0, N) << endl;
    
    return 0;
}
