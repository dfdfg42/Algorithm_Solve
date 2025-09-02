#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> s) {
    vector<string> answer;

    for (const string& str : s) {
        string temp_str = "";
        int count_110 = 0;   
        for (char c : str) {
            temp_str += c;
            if (temp_str.length() >= 3) {
                if (temp_str.substr(temp_str.length() - 3) == "110") {
                    count_110++;
                    temp_str.resize(temp_str.length() - 3);
                }
            }
        }

        if (count_110 > 0) {
            string to_insert = "";
            for (int i = 0; i < count_110; ++i) {
                to_insert += "110";
            }

            size_t last_zero_pos = temp_str.find_last_of('0');

            if (last_zero_pos == string::npos) {
                answer.push_back(to_insert + temp_str);
            } else {
                temp_str.insert(last_zero_pos + 1, to_insert);
                answer.push_back(temp_str);
            }
        } else {
            answer.push_back(str);
        }
    }

    return answer;
}