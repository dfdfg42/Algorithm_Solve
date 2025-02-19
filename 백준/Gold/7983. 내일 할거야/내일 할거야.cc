#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    vector<pair<int, int >> td;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int d, t;
        cin >> d >> t;
        td.push_back({ t,d });
    }

    sort(td.begin(), td.end(),greater<>());


    //for (auto a : td) {
    //    cout <<  a.first << ' ' << a.second << '\n';
    //}

    int end = td[0].first;
    for (int i = 0; i<td.size(); i++) {
        if (end <= td[i].first) {
            end -= td[i].second;
        }
        else {
            end = td[i].first;
            end -= td[i].second;
        }
        //cout << "td first : " << td[i].first << " " << "td second: " << td[i].second << '\n';
        //cout << "end : " << end << '\n';
    }

    cout << end << '\n';
   
}

