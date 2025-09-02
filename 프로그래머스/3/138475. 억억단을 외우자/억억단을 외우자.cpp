#include <vector>

using namespace std;

vector<int> solution(int e, vector<int> starts) {

    vector<int> divisorCounts(e + 1, 0);
    for (int i = 1; i <= e; ++i) {
        for (int j = i; j <= e; j += i) {
            divisorCounts[j]++;
        }
    }

    
    vector<int> maxNum(e + 1, 0);
    maxNum[e] = e;
    for (int i = e - 1; i >= 1; --i) {
        if (divisorCounts[i] >= divisorCounts[maxNum[i + 1]]) {
            maxNum[i] = i;
        } else {
            maxNum[i] = maxNum[i + 1];
        }
    }


    vector<int> answer;
    for (int s : starts) {
        answer.push_back(maxNum[s]);
    }

    return answer;
}