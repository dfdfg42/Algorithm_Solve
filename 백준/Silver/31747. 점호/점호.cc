#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <deque>;

using namespace std;

int main() {

    int n, k;
    cin >> n >> k;

    deque<int> line(n);
    deque<int> grade1;
    deque<int> grade2;
    int lineSize = line.size();

    for (int i = 0; i < n; i++) {
        cin >> line[i];
 
        if (line[i] == 1) {
            grade1.push_back(i);
        }
        else {
            grade2.push_back(i);
        }
    }


    int time = 0;
    int index = 0;

    while (index < line.size()) {


        //남은 인덱스 확인
        int checkLength = index + k - 1;
        checkLength = min(lineSize -1 , checkLength);

        if (!grade1.empty() && grade1.front() <= checkLength) {
            index++;
            grade1.pop_front();
        }
        if (!grade2.empty() && grade2.front() <= checkLength) {
            index++;
            grade2.pop_front();
        }

        time++;
    }

    cout << time << '\n';

    return 0;
}
