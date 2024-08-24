#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// 다음 순열을 찾는 함수
string next_permutation_string(string s) {
    int i = s.size() - 2;

    // Step 2: 뒤에서부터 첫 번째 감소하는 위치를 찾습니다.
    while (i >= 0 && s[i] >= s[i + 1]) {
        i--;
    }

    // 만약 i가 -1이면, 현재 순열이 가장 큰 순열이므로 다음 순열이 없습니다.
    if (i == -1) {
        return "BIGGEST";
    }

    // Step 3: s[i]보다 큰 첫 번째 숫자를 찾고, 둘의 자리를 바꿉니다.
    int j = s.size() - 1;
    while (s[j] <= s[i]) {
        j--;
    }
    swap(s[i], s[j]);

    // Step 4: i 뒤쪽의 숫자들을 오름차순으로 정렬합니다.
    reverse(s.begin() + i + 1, s.end());

    return s;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        string A;
        cin >> A;
        cout << next_permutation_string(A) << endl;
    }

    return 0;
}
