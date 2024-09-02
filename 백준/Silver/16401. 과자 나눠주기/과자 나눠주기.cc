#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> snack;

int snackDivide(int length) {
    int snackCount = 0;
    for (int i = 0; i < snack.size(); i++) {
        snackCount += snack[i] / length;  // 나눠줄 수 있는 과자 개수 계산
    }
    return snackCount;
}

int main() {
    int m, n;
    cin >> m >> n;

    snack.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> snack[i];
    }

    sort(snack.begin(), snack.end());

    int l = 1; 
    int r = snack[n - 1]; 
    int maxSnack = 0;

    while (l <= r) {
        int mid = (l + r) / 2;
        int temp = snackDivide(mid);

        if (temp >= m) {   
            maxSnack = mid;  
            l = mid + 1; 
        }
        else {
            r = mid - 1;  
        }
    }

    cout << maxSnack << '\n';

    return 0;
}
