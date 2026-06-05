#include <string>
#include <vector>
#include <algorithm>   

using namespace std;

struct node{
    int y;
    int x;
    int nodeNum;
    int left;          
    int right;         

    bool operator<(const node& other) const {
        if (y != other.y) return y > other.y;
        return x < other.x;
    }
};

vector<node> nodes;
int n;

void insert(int i){
    int cur = 0;
    while(true){
        if(nodes[i].x < nodes[cur].x){
            if(nodes[cur].left == -1){ nodes[cur].left = i; return; }
            cur = nodes[cur].left;
        } else {
            if(nodes[cur].right == -1){ nodes[cur].right = i; return; }
            cur = nodes[cur].right;
        }
    }
}

void preOrder(int index, vector<int>& seq){
    if(index == -1) return;               
    seq.push_back(nodes[index].nodeNum); 
    preOrder(nodes[index].left, seq);    
    preOrder(nodes[index].right, seq);   
}

void postOrder(int index, vector<int>& seq){
    if(index == -1) return;
    postOrder(nodes[index].left, seq);    
    postOrder(nodes[index].right, seq);  
    seq.push_back(nodes[index].nodeNum); 
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    n = nodeinfo.size();
    nodes.clear();        
    nodes.resize(n);

    for(int i = 0; i < n; i++){
        nodes[i] = {nodeinfo[i][1], nodeinfo[i][0], i + 1, -1, -1};  
    }

    sort(nodes.begin(), nodes.end());

    for(int i = 1; i < n; i++){
        insert(i);
    }

    vector<int> pre, post;
    preOrder(0, pre);
    postOrder(0, post);

    answer.push_back(pre);
    answer.push_back(post);

    return answer;
}