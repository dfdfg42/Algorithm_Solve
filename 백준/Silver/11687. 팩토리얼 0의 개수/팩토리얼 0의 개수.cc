#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;


//5가 들어간 개수를 찾는 함수
int findFive(int a) {
    int count = 0;

    for (int i = 5; i <= a; i *= 5) {
        count += (a / i);
    }
    return count;
}

int main() {

    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    //0의 개수는 5의 개수와 동일
    //제곱이 나오는 경우는 숫자가 건너뛰어짐
    int input;
    cin >> input;

    int left = 1;
    int right = input*5;
    int target = input;
    int result = 0;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (findFive(mid) == target) {
            right = mid -1;
        }
        else if (findFive(mid) > target) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    
    if (findFive(left) == target) {
        cout << left;
    }
    else {
        cout << -1;
    }
    
    return 0;
}