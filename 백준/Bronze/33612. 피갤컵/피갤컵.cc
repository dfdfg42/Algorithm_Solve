#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int year = 2024, month = 8;

    int totalMonths = (year * 12 + (month - 1)) + (N - 1) * 7;
    
    int resultYear = totalMonths / 12;
    int resultMonth = (totalMonths % 12) + 1;
    
    cout << resultYear << " " << resultMonth;
    return 0;
}