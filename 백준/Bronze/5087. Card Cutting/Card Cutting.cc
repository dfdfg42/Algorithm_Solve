#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;



int main() {
    vector<string> inputs;
    while (true) {

        string input;
        cin >> input; 
        if (input == "#") {
            return 0;
        }




        if (input == "*") {
            int c = 0;
            int t = 0;

            for (auto a : inputs) {
                if (a == "A") {
                    c++;
                }
                else if((stoi(a) % 2) == 0) {

                    t++;
                }
                else {
                    c++;
                }
            }

            //cout << t << ' ' << c << endl;

            if (t == c) {
                cout << "Draw" << '\n';
            }
            else if (t > c) {
                cout << "Tania" << '\n';
            }
            else {
                cout << "Cheryl" << '\n';
            }

            inputs.clear();
        }
        else {
            inputs.push_back(input);
        }


        

    }

    return 0;
}
