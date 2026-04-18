#include <string>
#include <vector>
#include <sstream>
#include <climits>

using namespace std;

string solution(string s) {
    
    stringstream ss(s);
    string token;
    
    int minVal = INT_MAX;
    int maxVal = INT_MIN;
    while(getline(ss, token, ' ')){
        minVal = min(stoi(token), minVal);
        maxVal = max(stoi(token),maxVal);
    }
    
    
    
    string answer = "";
    answer += to_string(minVal);
    answer += " ";
    answer += to_string(maxVal);
    return answer;
}