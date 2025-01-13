#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> balloons(n);
    vector<bool> popped(n, false);  // 풍선이 터졌는지 체크

    for (int i = 0; i < n; i++) {
        cin >> balloons[i];
    }

    vector<int> ans;
    ans.reserve(n);

   
    int index = 0;
    for (int count = 0; count < n; count++) {
  
        ans.push_back(index + 1); 
        popped[index] = true;       
        
        int move = balloons[index];

       
        balloons[index] = 0;

        

        if (count == n - 1) {
            
            break;
        }

        
        if (move > 0) {
            move -= 1;  
            
            do {
                index = (index + 1) % n;
            } while (popped[index]);
        }
        else {
            move += 1; 
            
            do {
                index = (index - 1 + n) % n;
            } while (popped[index]);
        }

       
        if (move > 0) {
            
            while (move > 0) {
                index = (index + 1) % n;
                if (!popped[index]) {
                    move--;
                }
            }
        }
        else if (move < 0) {
    
            while (move < 0) {
                index = (index - 1 + n) % n;
                if (!popped[index]) {
                    move++;
                }
            }
        }

    }


    for (int i = 0; i < n; i++) {
        cout << ans[i] << (i < n - 1 ? ' ' : '\n');
    }

    return 0;
}
