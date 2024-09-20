#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 월별 일수
int month_days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

// 날짜를 일수로 변환 (mm-dd 형식 -> 1~365 일수)
int date_to_day(const string& mm_dd) {
    int month = stoi(mm_dd.substr(0, 2));
    int day = stoi(mm_dd.substr(3, 2));
    int day_number = day;
    for (int i = 0; i < month - 1; ++i) {
        day_number += month_days[i];
    }
    return day_number;
}

// 일수를 날짜로 변환 (1~365 일수 -> mm-dd 형식)
string day_to_date(int day_number) {
    int month = 0;
    while (day_number > month_days[month]) {
        day_number -= month_days[month];
        ++month;
    }
    char buffer[6];
    sprintf(buffer, "%02d-%02d", month + 1, day_number);
    return string(buffer);
}

int main() {
    int n;
    cin >> n;
    vector<bool> occupied_days(366, false); // 1~365 사용
    for (int i = 0; i < n; ++i) {
        string name, mm_dd;
        cin >> name >> mm_dd;
        int day_number = date_to_day(mm_dd);
        occupied_days[day_number] = true;
    }

    int days_in_year = 365;
    vector<int> time_since_last_birthday(days_in_year + 1, 0); // 1~365 사용
    int time_since_last = days_in_year;

    // 현재 날짜를 일수로 변환
    int current_date_number = date_to_day("10-27");

    // 2년치 날짜를 순회하여 wrap-around 처리
    for (int i = 1; i <= days_in_year * 2; ++i) {
        int day_idx = (i - 1) % days_in_year + 1;
        if (occupied_days[day_idx]) {
            time_since_last = 0;
        } else {
            time_since_last++;
        }
        if (i > days_in_year) {
            time_since_last_birthday[day_idx] = time_since_last;
        }
    }

    // 최대 기간 찾기
    int max_time = *max_element(time_since_last_birthday.begin() + 1, time_since_last_birthday.end());
    vector<int> candidate_days;
    for (int day = 1; day <= days_in_year; ++day) {
        if (!occupied_days[day] && time_since_last_birthday[day] == max_time) {
            candidate_days.push_back(day);
        }
    }

    // 타이브레이크 처리
    int selected_day = -1;
    sort(candidate_days.begin(), candidate_days.end());
    for (int day : candidate_days) {
        if (day > current_date_number) {
            selected_day = day;
            break;
        }
    }
    if (selected_day == -1 && !candidate_days.empty()) {
        selected_day = candidate_days[0];
    }

    // 결과 출력
    string result_date = day_to_date(selected_day);
    cout << result_date << endl;

    return 0;
}
