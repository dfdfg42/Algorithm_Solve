#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int last = 1;

    for(auto s : stations){
        int uncovered = s - w - last;
        if(uncovered > 0)
            answer += (int)ceil(double(uncovered) / double(2*w+1));
        last = s + w + 1;
    }

    int uncovered = n - last + 1;
    if(uncovered > 0)
        answer += (int)ceil(double(uncovered) / double(2*w+1));

    return answer;
}