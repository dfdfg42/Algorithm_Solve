#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, t;
    cin >> n >> k >> t;

    vector<int> vec(n);

    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());

    int left = 0;
    int right = vec.size()-1;
    long long count = 0;

         
    while (left < right) {
        

        if (vec[right] == k) {
            right--;
            if (left >= right) {
                break;
            }
        }
        else if (vec[right] < k) {

            int temp = k - vec[right];
            
            if (temp > vec[left]) {
                count += vec[left];   
                vec[right] += vec[left];
                vec[left] = 0;
                left++;
            }
            else if (temp < vec[left]) {
                vec[left] -= temp;
                vec[right] += temp;
                right--;
                count += temp;
            }
            else if (temp == vec[left]) { 
                vec[left] = 0;
                vec[right] += temp;
                left++;
                right--;
                count += temp;
            }
            
        }


        if(vec[left] < k && vec[right] > k) {

            int temp = k - vec[left];
            int temp2 = vec[right] - k;

            if (vec[right] - temp >= k) {
                vec[right] -= temp;
                vec[left] += temp;
                count += temp;
                left++;
            }
            else {
                vec[right] -= temp2;
                vec[left] += temp2;
                count += temp2;
                right--;
            }
    
        }
        else if (vec[left] == k || vec[left] == 0) {
            left++;
        }

        //cout << " left : " << left << endl;
        //cout << " right : " << right << endl;
        //cout << " vec left : " << vec[left] << endl;
        //cout << " vec right : " << vec[right] << endl;

    }



    for (auto a : vec) {
        if (a != k && a!=0) {
            cout << "NO" << '\n';
            return 0;
        }
    }
    if (count <= t) {
        ;
        cout << "YES" << '\n';
    }
    else {
        cout << "NO" << '\n';
    }
    return 0;
}
