#include <iostream>
#include<string>
#include <vector>

using namespace std;

int solution(string s)
{
    int answer = -1;
    int len = s.length();

    char * stk = new char[len+1];
    int top = 0;
    stk[top++] = '!';

    
    for (int i = 0; i < len; i++) {
        if (stk[top - 1] != s[i]) {
            stk[top++] = s[i];
        } else {
            top--;
        }
    }

    answer = (top == 1) ? 1 : 0;
    delete[] stk;
 
    return answer;
}