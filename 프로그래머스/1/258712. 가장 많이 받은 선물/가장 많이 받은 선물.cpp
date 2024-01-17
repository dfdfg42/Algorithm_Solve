#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <sstream>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    
    int fSize = friends.size();
    vector<vector<int>> giftCount (fSize, vector<int> (fSize, 0)); //주고받은 선물
    vector<int> giftFactor (fSize,0); //선물 지수
    vector<int> giftRank (fSize,0); // 다음달 받을 선물 개수
    
    //친구들의 인덱스와 이름 매칭
    map<string,int> friendsMap;
    for(int i=0; i<fSize; i++){
        friendsMap.insert({friends[i],i});
    }
    
    for(string s : gifts){
        string first,second;
        stringstream ss (s);
        
        ss >> first >> second;
        
        
        giftCount[friendsMap[first]][friendsMap[second]]++;
        giftFactor[friendsMap[first]]++;
        giftFactor[friendsMap[second]]--;
        
        //cout << first << " " << second << endl;
        //cout << friendsMap[first] << " " << friendsMap[second] << endl;
        
    }
    
    //테스트 출력 코드
    for(int i=0; i < fSize; i++){
        for(int j=0; j<fSize; j++){
            cout << giftCount[i][j] << " ";
        }
        cout << endl;
    }
    
    for(int a : giftFactor){
        cout << a << endl;
    }
    
    
    //선물 개수 갱신
    int max = 0;
    for(int i=0; i<fSize; i++){
        for(int j=0; j<fSize; j++){
            if(i != j){
                if(giftCount[i][j] > giftCount[j][i]){
                    giftRank[i]++;
                    if(giftRank[i]> max){
                        max = giftRank[i];
                    }
                }
                else if(giftCount[i][j] == giftCount[j][i]){
                    if(giftFactor[i] > giftFactor[j]){
                        giftRank[i]++;
                        if(giftRank[i]>max){
                            max = giftRank[i];
                        }
                    }
                }
            }
        }
    }
    
    

    
    
    return max;
    
    
}