#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int total = brown + yellow;

    for (int w = 3; w <= total; w++) {
        if (total % w != 0) continue;  
        int h = total / w;
        if (w < h) continue;            
        if (2 * w + 2 * h - 4 == brown) {
            answer.push_back(w);
            answer.push_back(h);
            break;
        }
    }

    return answer;
}