#define _CRT_SECURE_NO_WARNINGS 

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;


int main() {

    int N, K;
    cin >> N >> K;
    int arr[2][7] = { { 0,0 },
                    {0,0,0,0,0,0,0} };

    int S, Y;
    for (int i = 0; i < N; i++) {
        cin >> S >> Y;

        arr[S][Y]++;

        //cout << " arr[S][Y] " << arr[S][Y] <<" ||| \n";
    }
    int cnt = 0;

    for (int j = 0; j <= 1; j++) {
        for (int k = 1; k <= 6; k++) {
            while (arr[j][k] > 0) {
                arr[j][k] -= K;
                cnt++;
                //cout << "K-" << j << "   " << k << "\n";
            }
        }
    }

    cout << cnt;

    
    return 0;
}