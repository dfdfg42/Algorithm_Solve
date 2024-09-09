#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int k, l;
    cin >> k >> l;

    map<string, int> students;
    int num = 0;

    for (int i = 0; i < l; i++) {
        string s;
        cin >> s;
        students[s] = ++num;
    }

    // map의 데이터를 vector로 이동
    vector<pair<string, int>> sorted_students(students.begin(), students.end());

    // 값을 기준으로 정렬
    sort(sorted_students.begin(), sorted_students.end(),
        [](const pair<string, int>& a, const pair<string, int>& b) {
            return a.second < b.second; // 값을 기준으로 오름차순 정렬
        });

    // k명의 학생을 출력
    for (int i = 0; i < k && i < sorted_students.size(); i++) {
        cout << sorted_students[i].first << '\n';
    }

    return 0;
}
