#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
vector<vector<int>> board;
vector<vector<bool>> visited;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

struct Group {
    int size;
    int rainbowCount;
    int baseRow;
    int baseCol;
    vector<pair<int, int>> blocks;
};

void gravity() {
    for (int j = 0; j < n; j++) {
        int bottom = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (board[i][j] == -1) {
                bottom = i - 1;
            } else if (board[i][j] != -2) {
                if (i != bottom) {
                    board[bottom][j] = board[i][j];
                    board[i][j] = -2;
                }
                bottom--;
            }
        }
    }
}

void rotate() {
    vector<vector<int>> temp(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[n - 1 - j][i] = board[i][j];
        }
    }
    board = temp;
}

Group findGroup(int startR, int startC, int color) {
    if (color <= 0 || visited[startR][startC]) {
        return {0, 0, -1, -1, {}};
    }
    
    queue<pair<int, int>> q;
    vector<pair<int, int>> blocks;
    vector<pair<int, int>> rainbowBlocks;
    
    q.push({startR, startC});
    visited[startR][startC] = true;
    blocks.push_back({startR, startC});
    
    int baseRow = startR, baseCol = startC;
    int rainbowCount = 0;
    
    while (!q.empty()) {
        pair<int, int> current = q.front();
        int r = current.first;
        int c = current.second;
        q.pop();
        
        for (int d = 0; d < 4; d++) {
            int nr = r + dy[d];
            int nc = c + dx[d];
            
            if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
            if (visited[nr][nc]) continue;
            
            if (board[nr][nc] == color || board[nr][nc] == 0) {
                visited[nr][nc] = true;
                q.push({nr, nc});
                blocks.push_back({nr, nc});
                
                if (board[nr][nc] == 0) {
                    rainbowCount++;
                    rainbowBlocks.push_back({nr, nc});
                } else {
                    // 일반 블록 중에서 기준 블록 갱신
                    if (nr < baseRow || (nr == baseRow && nc < baseCol)) {
                        baseRow = nr;
                        baseCol = nc;
                    }
                }
            }
        }
    }
    
    // 무지개 블록의 visited를 false로 되돌림
    for (int i = 0; i < rainbowBlocks.size(); i++) {
        visited[rainbowBlocks[i].first][rainbowBlocks[i].second] = false;
    }
    
    return {(int)blocks.size(), rainbowCount, baseRow, baseCol, blocks};
}

Group findLargestGroup() {
    visited.assign(n, vector<bool>(n, false));
    Group best = {0, 0, -1, -1, {}};
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] > 0 && !visited[i][j]) {
                Group current = findGroup(i, j, board[i][j]);
                
                if (current.size >= 2) {
                    bool isBetter = false;
                    
                    if (current.size > best.size) {
                        isBetter = true;
                    } else if (current.size == best.size) {
                        if (current.rainbowCount > best.rainbowCount) {
                            isBetter = true;
                        } else if (current.rainbowCount == best.rainbowCount) {
                            if (current.baseRow > best.baseRow) {
                                isBetter = true;
                            } else if (current.baseRow == best.baseRow) {
                                if (current.baseCol > best.baseCol) {
                                    isBetter = true;
                                }
                            }
                        }
                    }
                    
                    if (isBetter) {
                        best = current;
                    }
                }
            }
        }
    }
    
    return best;
}

void removeGroup(const Group& group) {
    for (int i = 0; i < group.blocks.size(); i++) {
        board[group.blocks[i].first][group.blocks[i].second] = -2;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    board.resize(n, vector<int>(n));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    
    int totalScore = 0;
    
    while (true) {
        Group largestGroup = findLargestGroup();
        
        if (largestGroup.size < 2) {
            break;
        }
        
        removeGroup(largestGroup);
        totalScore += largestGroup.size * largestGroup.size;
        
        gravity();
        rotate();
        gravity();
    }
    
    cout << totalScore << '\n';
    return 0;
}