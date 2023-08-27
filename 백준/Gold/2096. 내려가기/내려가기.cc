#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, num;
    cin >> n;

    int minArr[3], maxArr[3], minTmp[3], maxTmp[3];
    int input[3];

    for(int i = 0 ; i < n ; i++){
        cin >> input[0] >> input[1] >> input[2];

        if(i == 0) {
            for(int j = 0 ; j < 3 ; j++) minTmp[j] = maxTmp[j] = minArr[j] = maxArr[j] = input[j];
            continue;
        }

        minArr[0] = input[0] + min(minTmp[0], minTmp[1]);
        maxArr[0] = input[0] + max(maxTmp[0], maxTmp[1]);

        minArr[1] = input[1] + min({minTmp[0], minTmp[1], minTmp[2]});
        maxArr[1] = input[1] + max({maxTmp[0], maxTmp[1], maxTmp[2]});

        minArr[2] = input[2] + min(minTmp[1], minTmp[2]);
        maxArr[2] = input[2] + max(maxTmp[1], maxTmp[2]);

        for(int j = 0 ; j < 3 ; j++){
            minTmp[j] = minArr[j];
            maxTmp[j] = maxArr[j];
        }
    }
    
    cout << *max_element(maxArr, maxArr + 3) << " " << *min_element(minArr, minArr + 3);

    return 0;
}