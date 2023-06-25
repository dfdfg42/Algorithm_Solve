#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    //닫는거만 세주면 됩니다
    //여는 괄호에서 닫는 거 개수만큼 차감해주고 마이너스가 된다면 VPS가 아니죠
    int n;
    cin >> n;

    while (n--) {
        string input;
        cin >> input;
        int vpsCount = 0;
        bool minus = false;

        for (int i = 0; i < input.size(); i++) {

            if (input[i] == '(') {
                vpsCount++;
            }
            else {
                vpsCount--;
            }
            if (vpsCount < 0) {
                cout << "NO" << "\n";
                minus = true;
                break;
            }
        }

        if (minus == false) {
            if (vpsCount != 0) {
                cout << "NO" << "\n";
            }
            else {
                cout << "YES" << "\n";
            }
        }
    }
    
    return 0;
}