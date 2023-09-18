#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int paper[129][129];
int white = 0;
int blue = 0;

void go(int x, int y, int size) {
    int rootColor = paper[x][y];

    bool shouldCut = false;
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (paper[i][j] != rootColor) {
                shouldCut = true;
                break;
            }
        }
    }
    if (shouldCut) {
        go(x, y, size / 2); // 좌측 위
        go(x + size / 2, y, size / 2); // 우측 위
        go(x, y + size / 2, size / 2);
        go(x + size / 2, y + size / 2, size / 2);//우측 하단

    }
    else {
        if (rootColor == 0) {
            white++;
        }
        else {
            blue++;
        }
    }
    

}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> paper[i][j];
        }
    }
    go(0, 0, n);

    cout << white << "\n" << blue << "\n";
}
