#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>

using namespace std;

vector<vector<string>> board;
vector<vector<int>> mergeMap;
int mergeCnt;


void Update(int r, int c, string value){
    
    board[r][c] = value;
    
    if(mergeMap[r][c] != -1){
        int val = mergeMap[r][c];
        for(int i=1; i<=50; i++){
            for(int j=1; j<=50; j++){
                if(mergeMap[i][j] == val) board[i][j] = value;
            }
        }
    }
    
    return;
}

void Update(string value1,string value2){
    
    set<int> s; // mergeMap 조회용
    for(int i=1; i<=50; i++){
        for(int j=1; j<=50; j++){
            if(board[i][j] == value1 || s.find(mergeMap[i][j]) != s.end() ){
                if(mergeMap[i][j] != -1 )s.insert(mergeMap[i][j]);
                board[i][j] = value2;
            }
        }
    }
    
    return;
    
}

void Merge(int r1, int c1 , int r2 , int c2){
    
    int group1 = mergeMap[r1][c1];
    int group2 = mergeMap[r2][c2];

    if (r1 == r2 && c1 == c2) {
        return;
    }

    if (group1 != -1 && group1 == group2) {
        return;
    }
    
    int mergeNum = -1;
    if(mergeMap[r1][c1] != -1 || mergeMap[r2][c2] != -1){
        mergeNum = max(mergeMap[r1][c1], mergeMap[r2][c2]);    
    }
    
    string val = "";
    if (!board[r1][c1].empty()) {
        val = board[r1][c1];
    } else {
        val = board[r2][c2];
    }
    
    if (mergeNum == -1) {
        mergeNum = mergeCnt++;
    }
    set<int> s;
    if(group1 != -1) s.insert(group1);
    if(group2 != -1) s.insert(group2);
    mergeMap[r1][c1] = mergeNum;
    mergeMap[r2][c2] = mergeNum;

    for(int i=1; i<=50; i++){
        for(int j=1; j<=50; j++){
            if(s.find(mergeMap[i][j]) != s.end() ){
                mergeMap[i][j] = mergeNum;
                board[i][j] = val;
            }
        }
    }
    
    board[r2][c2] = val;
    board[r1][c1] = val;
    
}

void Unmerge(int r, int c){
    
    int mergeNum = mergeMap[r][c];
     if(mergeNum == -1) return;
    
    for(int i=1; i<=50; i++){
        for(int j=1; j<=50; j++){
            if(mergeMap[i][j] == mergeNum && !(r== i && c == j)){
                mergeMap[i][j] = -1;
                board[i][j] = "";
            }
        }
    }
    mergeMap[r][c] = -1;
}

string Print(int r, int c){
    return board[r][c].empty() ? "EMPTY" : board[r][c];
}

vector<string> solution(vector<string> commands) {
    vector<string> answer;
    
    board.resize(51, vector<string>(51,""));
    mergeMap.resize(51,vector<int>(51,-1));
    mergeCnt = 0;
    
    for (const auto& commandLine : commands) {
        stringstream ss(commandLine);

        string command;
        ss >> command;

        if (command == "UPDATE") {
            vector<string> args;
            string token;

            while (ss >> token) {
                args.push_back(token);
            }

            if (args.size() == 3) {
                int r = stoi(args[0]);
                int c = stoi(args[1]);
                string value = args[2];

                Update(r,c,value);
            }
            else if (args.size() == 2) {
                string value1 = args[0];
                string value2 = args[1];

                Update(value1, value2);
            }
        }
        else if (command == "MERGE") {
            int r1, c1, r2, c2;
            ss >> r1 >> c1 >> r2 >> c2;

            Merge(r1,c1,r2,c2);
        }
        else if (command == "UNMERGE") {
            int r, c;
            ss >> r >> c;

            Unmerge(r,c);
        }
        else if (command == "PRINT") {
            int r, c;
            ss >> r >> c;

            answer.push_back(Print(r,c));
        }
    }
    
    return answer;
}