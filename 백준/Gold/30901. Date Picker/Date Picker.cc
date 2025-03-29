#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;

vector<string> schedule(7);


void dfs(int start, int k, vector<int>& cur, vector<vector<int>>& res) {

    if(cur.size() == k) {
        res.push_back(cur);
        return;
    }
 
    for (int i = start; i < 7; i++) {
        cur.push_back(i);             
        dfs(i + 1, k, cur, res);        
        cur.pop_back();                
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

  
    for (int i = 0; i < 7; i++){
        cin >> schedule[i];
    }
    
    int d, h;
    cin >> d >> h;
    
    double bestProb = 0.0;
    

    for (int numDays = d; numDays <= 7; numDays++){
        vector<vector<int>> dayComb; 
        vector<int> cur;
        dfs(0, numDays, cur, dayComb); 
        
        
        for (auto& comb : dayComb) {
            
            vector<int> freeCount(24, 0);
            for (int hour = 0; hour < 24; hour++){
                for (int day : comb) {
                    if (schedule[day][hour] == '.') {
                        freeCount[hour]++;
                    }
                }
            }
            
            
            sort(freeCount.begin(), freeCount.end(), greater<int>());
            int sumFree = 0;
            for (int i = 0; i < h; i++){
                sumFree += freeCount[i];
            }
            
           
            double prob = (double) sumFree / (numDays * h);
            bestProb = max(bestProb, prob);
        }
    }
    
    cout << fixed << setprecision(12) << bestProb << "\n";
    return 0;
}
