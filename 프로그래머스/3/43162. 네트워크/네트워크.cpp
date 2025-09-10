#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> parents;

int FIND(int a){
    if(parents[a] != a){
        parents[a] = FIND(parents[a]);
    }
    return parents[a];
}

void UNION(int a,int b){
    a = FIND(a);
    b = FIND(b);
    if(a != b)
        parents[a] = b;
}


int solution(int n, vector<vector<int>> computers) {
    
    parents.resize(n);
    for(int i=0; i<n; i++){
        parents[i] = i;
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j) continue;
            
            if(computers[i][j] == 1 ){
                UNION(i,j);
            }
        }
    }
    
    set<int> network;
    
    for(int i=0; i<n; i++){
        network.insert(FIND(i));
    }
    
    
    
    
    int answer = network.size();
    return answer;
}