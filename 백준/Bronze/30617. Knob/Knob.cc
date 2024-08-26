#include <iostream>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int prev_left = 0, prev_right = 0;
    int curr_left, curr_right;
    int T, fun_score = 0;

    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> curr_left >> curr_right;

        if (t > 0)
        {
            // 같은 방향으로 돌린 경우
            if (prev_left == curr_left && curr_left != 0) fun_score++;
            if (prev_right == curr_right && curr_right != 0) fun_score++;
        }

        // 양쪽 노브가 같은 방향으로 돌린 경우
        if (curr_left == curr_right && curr_left != 0) fun_score++;

        // 현재 노브 상태를 이전 상태로 업데이트
        prev_left = curr_left;
        prev_right = curr_right;
    }

    cout << fun_score;
    return 0;
}
