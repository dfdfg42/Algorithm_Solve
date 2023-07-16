#include<queue>
#include<deque>
#include <iostream>

using namespace std;

int main() {
    int arr[100][100];


    int count = 1;

    while (1) {
        int N; cin >> N;
        if (!N) break;
        //i 세로 j 가로

        int temp = 0;
        int max = -987654321;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> arr[i][j];
            }
        }

        // ㅡ
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N - 3; j++) {
                temp = 0;
                temp = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i][j + 3];
                if (temp > max) max = temp;
            }
        }
        // ㅣ
        for (int i = 0; i < N - 3; i++) {
            for (int j = 0; j < N; j++) {
                temp = 0;
                temp = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 3][j];
                if (temp > max) max = temp;
            }
        }

        //ㅓ
        for (int i = 0; i < N - 2; i++) {
            for (int j = 0; j < N - 1; j++) {
                temp = 0;
                temp = arr[i + 1][j] + arr[i + 1][j + 1] + arr[i][j + 1] + arr[i + 2][j + 1];
                if (temp > max) max = temp;
            }
        }
        //ㅗ
        for (int i = 0; i < N - 1; i++) {
            for (int j = 0; j < N - 2; j++) {
                temp = 0;
                temp = arr[i + 1][j] + arr[i + 1][j + 1] + arr[i][j + 1] + arr[i + 1][j + 2];
                if (temp > max) max = temp;
            }
        }
        //ㅜ
        for (int i = 0; i < N - 1; i++) {
            for (int j = 0; j < N - 2; j++) {
                temp = 0;
                temp = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 1];
                if (temp > max) max = temp;
            }
        }
        //ㅏ
        for (int i = 0; i < N - 2; i++) {
            for (int j = 0; j < N - 1; j++) {
                temp = 0;
                temp = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 1][j + 1];
                if (temp > max) max = temp;
            }
        }
        //ㅁ
        for (int i = 0; i < N - 1; i++) {
            for (int j = 0; j < N - 1; j++) {
                temp = 0;
                temp = arr[i][j] + arr[i][j + 1] + arr[i + 1][j] + arr[i + 1][j + 1];
                if (temp > max) max = temp;
            }
        }
        //ㅁㅁ
        //  ㅁㅁ
        for (int i = 0; i < N - 1; i++) {
            for (int j = 0; j < N - 2; j++) {
                temp = 0;
                temp = arr[i][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 1][j + 2];
                if (temp > max) max = temp;
            }
        }

        //  ㅁ
        //ㅁㅁ
        //ㅁ

        for (int i = 0; i < N - 2; i++) {
            for (int j = 0; j < N - 1; j++) {
                temp = 0;
                temp = arr[i][j+1] + arr[i + 1][j+1] + arr[i + 1][j] + arr[i +2][j];
                if (temp > max) max = temp;
            }
        }



        //ㅁㅁㅁ
        //    ㅁ

        for (int i = 0; i < N - 1; i++) {
            for (int j = 0; j < N - 2; j++) {
                temp = 0;
                temp = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 2];
                if (temp > max) max = temp;
            }
        }
        //  ㅁ
        //  ㅁ
        //ㅁㅁ

        for (int i = 0; i < N - 2; i++) {
            for (int j = 0; j < N - 1; j++) {
                temp = 0;
                temp = arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 2][j+1] + arr[i + 2][j];
                if (temp > max) max = temp;
            }
        }

        //ㅁ
        //ㅁㅁㅁ

        for (int i = 0; i < N - 1; i++) {
            for (int j = 0; j < N - 2; j++) {
                temp = 0;
                temp = arr[i][j] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 1][j + 2];
                if (temp > max) max = temp;
            }
        }

        //ㅁㅁ
        //ㅁ
        //ㅁ

        for (int i = 0; i < N - 2; i++) {
            for (int j = 0; j < N - 1; j++) {
                temp = 0;
                temp = arr[i][j + 1] + arr[i][j] + arr[i + 1][j] + arr[i + 2][j];
                if (temp > max) max = temp;
            }
        }

        cout << count << ". " << max << endl;

        count++;
    }
    


    
}