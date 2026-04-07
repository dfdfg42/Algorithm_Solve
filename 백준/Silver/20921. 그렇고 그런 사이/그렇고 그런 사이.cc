#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    //남은 순서
    int leftN = K;

    //현재 몇번째 큰 거인지 
    int bigN = N ;

    if (K == 0) {
        for (int i = 1; i <= N; i++) {
            cout << i << ' ';
        }
        return 0;
    }

    while (leftN > 0) {

        if (leftN > bigN-1) {
            cout << bigN << ' ';
            leftN -= bigN - 1;
            bigN -= 1;
        }
        else {

            int i = 1;
            int tempBigN = bigN;
            //남은 게 더 작음
            while (leftN < tempBigN-1) {
                
                cout << i << ' ';
                i++;
                
                tempBigN--;
            }

            leftN = 0;
            cout << bigN << ' ';

            for (i; i < bigN; i++) {
                cout << i << ' ';
            }
            return 0;
        }

    }

    

    //남은 순서가 현재 큰 순서보다 크면
    //맨 앞에 삽입하고 
    //남은 순서를 bigN-1 만큼 줄임

    //남은 순서가 현재 큰 순서보다 작으면

    // 0이 될때 까지 한칸씩 넘긴뒤에 삽입
    

    return 0;
}