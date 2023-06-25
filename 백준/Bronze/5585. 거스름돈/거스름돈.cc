#include <iostream>
#include<string>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int input;
    cin >> input;
    int cnt = 0;
    input = 1000 - input;

    cnt += input / 500;
    input = input % 500;

    cnt += input / 100;
    input = input % 100;

    cnt += input / 50;
    input = input % 50;

    cnt += input / 10;
    input = input % 10;

    cnt += input / 5;
    input = input % 5;

    cnt += input / 1;
    input = input % 1;

    cout << cnt;

}