#include <iostream>

using namespace std;

int main() {
    int arr[100];

    int C, P;
    cin >> C >> P;

    int result = 0;
    for (int i = 0; i < C; i++) {
        cin >> arr[i];
    }

    // 1번블록 
    if (P == 1) {
        for (int i = 0; i < C; i++) {
            result += 1;
        }
        for (int i = 0; i < C-3; i++) {
            if (arr[i] == arr[i + 1] && arr[i + 1] == arr[i+2] && arr[i+2] == arr[i+3])
                result += 1;
           
        }
    }

    // 2번블록
    if (P == 2) {
        for (int i = 0; i < C-1; i++) {
            if(arr[i] == arr[i+1])
            result += 1;
        }
    }
    
    // 3번블록

    if (P == 3) {
        //001
        for (int i = 0; i < C - 2; i++) {
            if (arr[i] == arr[i + 1] && arr[i+1] == arr[i+2] -1)
                result += 1;
        }
        //10
        for (int i = 0; i < C - 1; i++) {
            if (arr[i] == arr[i + 1]+1)
                result += 1;
        }
    }

    // 4번블록
    if (P == 4) {
        // 100
        for (int i = 0; i < C - 2; i++) {
            if (arr[i]  == arr[i + 1] +1 && arr[i+1] == arr[i + 2])
                result += 1;
        }
        //01
        for (int i = 0; i < C - 1; i++) {
            if (arr[i]== arr[i + 1] -1 )
                result += 1;
        }
    }

    // 5번블록
    if (P == 5) {
        //01
        for (int i = 0; i < C - 1; i++) {
            if (arr[i]  == arr[i + 1] -1)
                result += 1;
        }


        //10
        for (int i = 0; i < C - 1; i++) {
            if (arr[i] == arr[i + 1] + 1)
                result += 1;
        }

        //000
        for (int i = 0; i < C - 2; i++) {
            if (arr[i]  == arr[i + 1] && arr[i+1] == arr[i + 2])
                result += 1;
        }
        //101
        for (int i = 0; i < C - 2; i++) {
            if (arr[i] == arr[i + 1] +1 && arr[i+1]== arr[i + 2]-1)
                result += 1;
        }

    }

    //6번블록

    if (P == 6 ) {
        //000
        for (int i = 0; i < C - 2; i++) {
            if (arr[i] == arr[i + 1] && arr[i+1] == arr[i + 2])
                result += 1;
        }
        //011
        for (int i = 0; i < C - 2; i++) {
            if (arr[i] == arr[i + 1]-1 && arr[i+1] == arr[i + 2])
                result += 1;
        }
        //00
        for (int i = 0; i < C - 1; i++) {
            if (arr[i] == arr[i + 1] )
                result += 1;
        }
        //20
        for (int i = 0; i < C - 1; i++) {
            if (arr[i]  == arr[i + 1]+2)
                result += 1;
        }
        
    }

    //7번블록
    if (P == 7) {
        //000
        for (int i = 0; i < C - 2; i++) {
            if (arr[i] == arr[i + 1] && arr[i+1] == arr[i + 2])
                result += 1;
        }
        //110
        for (int i = 0; i < C - 2; i++) {
            if (arr[i] == arr[i + 1] && arr[i+1] == arr[i + 2] + 1)
                result += 1;
        }
        //00
        for (int i = 0; i < C - 1; i++) {
            if (arr[i]  == arr[i + 1])
                result += 1;
        }
        //02
        for (int i = 0; i < C - 1; i++) {
            if (arr[i]  == arr[i + 1] -2)
                result += 1;
        }
    }

    
    cout << result;

    
}