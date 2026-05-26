#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int toMinute(const string& time) {
    int h = stoi(time.substr(0, 2));
    int m = stoi(time.substr(3, 2));
    return h * 60 + m;
}

string toTime(int minute) {
    int h = minute / 60;
    int m = minute % 60;

    string hh = h < 10 ? "0" + to_string(h) : to_string(h);
    string mm = m < 10 ? "0" + to_string(m) : to_string(m);

    return hh + ":" + mm;
}

string solution(int n, int t, int m, vector<string> timetable) {
    vector<int> crew;

    for (const string& time : timetable) {
        crew.push_back(toMinute(time));
    }

    sort(crew.begin(), crew.end());

    int idx = 0;
    int answer = 0;

    for (int bus = 0; bus < n; bus++) {
        int busTime = 540 + bus * t;
        int boarding = 0;

        while (idx < crew.size() && crew[idx] <= busTime && boarding < m) {
            idx++;
            boarding++;
        }

        if (bus == n - 1) {
            if (boarding < m) {
                answer = busTime;
            } else {
                answer = crew[idx - 1] - 1;
            }
        }
    }

    return toTime(answer);
}