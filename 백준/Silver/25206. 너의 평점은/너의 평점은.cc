#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <iomanip>
#include <tuple>
#include <sstream>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    float gradePointsSum = 0; // 학점의 총합
    float totalScore = 0; // 총 점수 (학점 × 과목평점의 합)

    map<string, float> gradeToPoint = {
        {"A+", 4.5}, {"A0", 4.0},
        {"B+", 3.5}, {"B0", 3.0},
        {"C+", 2.5}, {"C0", 2.0},
        {"D+", 1.5}, {"D0", 1.0},
        {"F", 0.0}
    };

    for (int i = 0; i < 20; i++) {
        string objectName, grade;
        float credits;
        cin >> objectName >> credits >> grade;

        if (grade == "P") {
            continue; // P등급은 계산에서 제외
        }

        totalScore += credits * gradeToPoint[grade]; // (학점 × 과목평점)
        gradePointsSum += credits; // 학점의 총합 업데이트
    }

    cout << fixed << setprecision(4);
    cout << totalScore / gradePointsSum << '\n'; // 전공평점 출력

    return 0;
}
