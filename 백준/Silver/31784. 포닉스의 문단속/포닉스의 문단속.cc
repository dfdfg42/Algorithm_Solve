#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    int N, K;
    cin >> N >> K;

    //알파벳 25까지 있음
    
    //A 로 만들수 있으면 만들고 남은 K 가 부족하면
    //맨 뒤의 숫자에 사용

    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        int need = (26 - (s[i] - 'A')) % 26;
        //cout << s[i] << ' ' << need << '\n';

        if (i == s.length() - 1) {
            s[s.length() - 1] = 'A' + (s[s.length() - 1] + K - 'A') % 26;
            break;
        }
        if (need <= K ) {
            
            s[i] = 'A';
            K -= need;
        }


    }

    cout << s << '\n';


    return 0;
}