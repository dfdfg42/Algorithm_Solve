#include <iostream>
#include<string>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a, b;
    cin >> a >> b;
    
    //모두 5로 바꾼게 최솟값 모두 6으로 바꾼게 최대값
    for (int i = 0; i < a.length(); i++) {
        if (a[i] == '6') {
            a[i] = '5';
        }
    }
    for (int i = 0; i < a.length(); i++) {
        if (b[i] == '6') {
            b[i] = '5';
        }
    }
    cout << stoi(a) + stoi(b) << ' '; //문자열을 정수로 바꾸는 함수

    for (int i = 0; i < a.length(); i++) {
        if (a[i] == '5') {
            a[i] = '6';
        }
    }
    for (int i = 0; i < a.length(); i++) {
        if (b[i] == '5') {
            b[i] = '6';
        }
    }

    cout << stoi(a) + stoi(b);
}