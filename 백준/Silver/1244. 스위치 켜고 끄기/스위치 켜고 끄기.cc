#include <iostream>
#include <string>

using namespace std;


int main() {

    int a;
    cin >> a;



    int cnt[102];

    for (int i = 1; i <= a; i++) { //1부터 입력시키기
        cin >> cnt[i];
        //cout << cnt[i] << " ";
        
    } 

    int stdt;
    cin >> stdt;

    while (stdt--) {
        int sx, num; //성별, 번호 받기
        cin >> sx >> num;
        //cout << "sx" << sx << "num" << num << endl;
        if (sx == 1) { // 성별이 남자일 경우

            for(int i = num; i <= a; i += num) {
                if (cnt[i] == 0) {
                    cnt[i] = 1;
                }
                else if (cnt[i] == 1) {
                    cnt[i] = 0;
                }

            } 
        }
        if (sx == 2) { // 성별이 여자일 경우
            bool decal = true; //대칭인지 확인
            int index = 0;

            while (decal == true) {


                //cout << "num + index" << num + index << endl;
                //cout << "num - index" << num - index << endl;


                if (cnt[num + index] == cnt[num - index]) {
                    if (cnt[num + index] == 0) {
                        cnt[num + index] = 1;
                        cnt[num - index] = 1;
                    }
                    else if (cnt[num + index] == 1) {
                        cnt[num + index] = 0;
                        cnt[num - index] = 0;
                    }
                }
                else {
                    decal = false;
                }

                index++;
                if (num + index > a || num - index <= 0) {
                    decal = false;
                }
            }

        }
        

    }

    for (int i = 1; i <= a; i++) {

        cout << cnt[i] << " ";

        if (i % 20 == 0) {
            cout << "\n";
        }
    }

    

    return 0;

}