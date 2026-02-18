#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y;
    cin >> x >> y;

    int month_days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    string day_names[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

    int total_days = 0;

    for (int i = 1; i < x; i++) {
        total_days += month_days[i];
    }

    total_days += y;

    cout << day_names[total_days % 7] << endl;

    return 0;
}