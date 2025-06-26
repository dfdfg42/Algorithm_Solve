#include <string>
#include <vector>

using namespace std;

vector<int> g_info;
vector<int> tree[17];
int max_sheep = 0;

void dfs(int current_node, int sheep, int wolf, vector<int> next_nodes) {
    // 1. 현재 양/늑대 수 계산
    if (g_info[current_node] == 0) sheep++;
    else wolf++;

    // 2. 늑대에게 양이 잡아먹히는 경우, 더 이상 탐색 불가 (백트래킹)
    if (sheep <= wolf) {
        return;
    }

    // 3. 최대 양의 수 갱신
    max_sheep = max(max_sheep, sheep);

    // 4. 다음에 방문할 수 있는 노드들로 탐색 확장
    for (int i = 0; i < next_nodes.size(); i++) {
        int next_node = next_nodes[i];
        
        // 다음 탐색을 위한 새로운 'next_nodes' 벡터 생성
        vector<int> new_next_nodes = next_nodes;
        // 이번에 탐색할 노드는 제거
        new_next_nodes.erase(new_next_nodes.begin() + i); 
        
        // 이번에 탐색한 노드의 자식들을 다음 방문 가능 목록에 추가
        for (int child : tree[next_node]) {
            new_next_nodes.push_back(child);
        }
        
        // 재귀 호출
        dfs(next_node, sheep, wolf, new_next_nodes);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    g_info = info;
    for(auto& edge : edges){
        tree[edge[0]].push_back(edge[1]);
    }
    
    vector<int> initial_next_nodes;
    for(int child : tree[0]){
        initial_next_nodes.push_back(child);
    }
    
    max_sheep = 1;
    
    
    for (int i = 0; i < initial_next_nodes.size(); i++) {
        int start_node = initial_next_nodes[i];
        
        vector<int> next_nodes = initial_next_nodes;
        next_nodes.erase(next_nodes.begin() + i);
        
        for (int child : tree[start_node]) {
            next_nodes.push_back(child);
        }
        
        dfs(start_node, 1, 0, next_nodes);
    }
    
    return max_sheep;
}