#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<string> box;
    string input = "";
    while (true) {
        getline(cin, input); //한줄 통채로 입력받기
        if (input == "END") {
            break;
        }
        reverse(input.begin(), input.end()); //코드 뒤집기
        box.push_back(input);
        
    }
    for (int i = 0; i < box.size(); i++) {
        cout << box[i]<<"\n";
    }

}