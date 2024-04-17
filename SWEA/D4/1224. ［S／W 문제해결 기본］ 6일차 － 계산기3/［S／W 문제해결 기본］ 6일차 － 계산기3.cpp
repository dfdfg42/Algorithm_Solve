#include <iostream>
#include <stack>
#include <cctype> 

using namespace std;

int precedence(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for (int tc = 1; tc <= 10; tc++) {
        int t; cin >> t;

        string s;
        cin >> s;

        stack<char> st;
        string output;

        for (int i = 0; i < s.length(); i++) {
            char now = s[i];
      /*      cout << "now : " << now << '\n';*/

            if (isdigit(now)) {
                output += now;
            }
            else if (now == '(') {
                st.push(now);
            }
            else if (now == ')') {
                while (!st.empty() && st.top() != '(') {
                    output += st.top();
                    st.pop();
                }
                st.pop();
            }
            else {
                while (!st.empty() && precedence(st.top()) >= precedence(now)) {
                    output += st.top();
                    st.pop();
                }
                st.push(now);
            }
        }

        while (!st.empty()) {
            output += st.top();
            st.pop();
        }

        //cout << output << '\n';


        //계산
        stack<int> st2;
        for (int i = 0; i < output.length(); i++) {

            char now = output[i];
            if (isdigit(now)) {
                st2.push(now - '0');
            }
            else {
                char temp = output[i];
                int second = st2.top();
                st2.pop();
                int first = st2.top();
                st2.pop();
                if (temp == '+') {
                    st2.push(first + second);
                }
                else if (temp == '-') {
                    st2.push(first - second);
                }
                else if (temp == '*') {
                    st2.push(first * second);
                }
                else if (temp == '/') {
                    st2.push(first / second);
                }




            }

        }

        cout << '#' << tc << ' ' << st2.top() << '\n';
    }

    return 0;
}
