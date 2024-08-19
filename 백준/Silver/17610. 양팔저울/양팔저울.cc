#include <iostream>
#include <vector>
#include <cmath>


using namespace std;

vector<int> mess;
vector<int> makes;
vector<bool> check;
vector<bool> dfsCheck;
vector<int> messNext;

//한곳에 만들수 있는 모든 무게추 구하기
void dfs(int index,int sumMess) {

    for (int i = 0; i < mess.size(); i++) {
        if (dfsCheck[i] == false) {
            dfsCheck[i] = true;
            if (check[sumMess + mess[i]] == false) {
                check[sumMess + mess[i]] = true;
                messNext.push_back(sumMess + mess[i]);
                dfs(i,sumMess + mess[i]);
            }
            dfsCheck[i] = false;
        }
    }

}


int main()
{
    int k;
    cin >> k;
    int s = 0;
    mess.resize(k);
    check.resize(3000'001, false);
    dfsCheck.resize(3000'001, false);

    for (int i = 0; i < k; i++) {
        cin >> mess[i];
        s += mess[i];
        //cout << "s: " << s << '\n';
        messNext.push_back(mess[i]);
        check[mess[i]] = true;
    }

    for (int i = 0; i<mess.size(); i++) {
        dfsCheck[i] = true;
        dfs(i, mess[i]);

    }

    //두개 골라서 빼기
    for (int i = 0; i < messNext.size()-1; i++) {
        for (int j = i + 1; j < messNext.size(); j++) {
            if (check[abs(messNext[i] - messNext[j])] == false) {
                check[abs(messNext[i] - messNext[j])] = true;
            }
        }

    }

    ////무게확인
    //for (int i = 0; i <= s; i++) {
    //    if (check[i] == true) {
    //        cout << i << " ";
    //    }
    //}

    //안 만들어진 무게추 확인
    int count = 0;
    //cout << "count: ";
    for (int i = 1; i <= s; i++) {
        if (check[i] == false) {
            count++;
        }
    }
    cout << count << '\n';

}

