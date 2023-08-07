#include <string>
#include <vector>
#include <iostream>
int n,m;


using namespace std;

vector<vector<int>> rotate(vector<vector<int>> key){ // key 시계방향 90도 회전
    vector<vector<int>> tmp;
    tmp.resize(n,vector<int>(n,0));
    
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            tmp[i][j] = key[m-1-j][i];
        }
    }
    return tmp;
}



int match(){
    
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    
    bool answer = false;
    m = key[0].size(); n = lock[0].size();

    vector<vector<int>> newMap;
    newMap.resize(n*3,vector<int>(n*3,2)); // 확장된 자물쇠 m*3의 크기
    
    
    int countEmpty = 0;
    cout << "map: \n";
    for(int i=0;i<n;i++){ //lock 의 빈 공간 카운트
        for(int j=0;j<n;j++){
            if(lock[i][j] == 0){
                countEmpty++;
            } 
            newMap[i+m][j+m] = lock[i][j]; //newMap 갱신
            cout << lock[i][j] <<" "; //map 출력
        }
        cout << "\n";
    }
    
    cout << "key: \n";
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cout << key[i][j] << " ";
        }
        cout << "\n";
    }
    
    cout << "emptyCount: " << countEmpty << "\n";

    for(int k=0; k<4; k++){
        if(k != 0) key = rotate(key);

    
    for(int i=0;i<m*3;i++){ //match 인지 확인하기
        for(int j=0;j<m*3;j++){
            
            //lock에 맞는지 확인하는 구간
            int ansCount = 0;
            for(int i2=0; i2<m; i2++){
                for(int j2=0; j2<m; j2++){
                    if(i2 + i < n*3 && j2 + j <n*3){ //범위 제한
                        
                    
                    if(newMap[i+i2][j+j2] == 0 && key[i2][j2] == 1 ){ 
                            ansCount++;
                    }  
                    if(newMap[i+i2][j+j2] == 0 && key[i2][j2] == 0){ 
                            ansCount = -123456789;
                    } 
                    if(newMap[i+i2][j+j2] == 1 && key[i2][j2] == 1){ 
                            ansCount = -123456789;
                    } 
                        
                    }//범위지정
                }   
            }
            cout << ansCount << " ";
             if(ansCount == countEmpty){
                        answer = true;
                }
        }
        
    } 
        
    } // 회전
    
    
    
    return answer;

}