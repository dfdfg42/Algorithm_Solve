#include <iostream>
#include <vector>
#include <iomanip> 
#include <queue>
#include <algorithm>

using namespace std;

typedef long double ld;
typedef long long ll;

int n, m;
vector<vector<bool>> students;
vector<vector<bool>> schedules;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    schedules.resize(n,vector<bool>(51, false));

    //과목듣는 시간을 true 로 표시
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        for (int j = 0; j < c; j++) {
            int d;
            cin >> d;
            schedules[i][d] = true;
        }
    }

    cin >> m;
    students.resize(m, vector<bool>(51, false));

    for (int i = 0; i < m; i++) {
        int c;
        cin >> c;
        for (int j = 0; j < c; j++) {
            int d;
            cin >> d;
            students[i][d] = true;
        }

        int ans = 0;
        for (int f = 0; f < n; f++) {
            bool flag = true;
            for (int g = 0; g <= 50; g++) {
                if (schedules[f][g] == true && students[i][g] == false) {
                    flag = false;
                    break;
                }

            }
            if (flag) ans++;
        }
        cout << ans << '\n';
    }


    return 0;
}