#include <bits/stdc++.h>
using namespace std;

int r;
vector<vector<int>> game_board, table;
vector<vector<pair<int,int>>> blocks;
vector<char> used;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

void normalize(vector<pair<int,int>>& v){
    int my = INT_MAX, mx = INT_MAX;

    for (size_t i = 0; i < v.size(); ++i) {
        my = min(my, v[i].first);
        mx = min(mx, v[i].second);
    }
    for (size_t i = 0; i < v.size(); ++i) {
        v[i].first  -= my;
        v[i].second -= mx;
    }
    sort(v.begin(), v.end());
}

vector<pair<int,int>> rot90(vector<pair<int,int>>& src){
    vector<pair<int,int>> v;
    v.reserve(src.size());
    for (size_t i = 0; i < src.size(); ++i) {
        v.push_back({src[i].second, -src[i].first});
    }
    normalize(v);
    return v;
}


void dfs(int y, int x, int target,vector<vector<int>>& g,vector<pair<int,int>>& shape,int oy, int ox)
{
    g[y][x] = 2;
    shape.push_back({y - oy, x - ox});

    for (int d = 0; d < 4; ++d) {
        int ny = y + dy[d], nx = x + dx[d];
        if (ny < 0 || ny >= r || nx < 0 || nx >= r) continue;
        if (g[ny][nx] == target)
            dfs(ny, nx, target, g, shape, oy, ox);
    }
}

int solution(vector<vector<int>> _game_board,vector<vector<int>> _table)
{
    game_board.swap(_game_board);
    table.swap(_table);
    r = (int)game_board.size();

    {
        vector<vector<int>> t(table);  
        for (int y = 0; y < r; ++y)
            for (int x = 0; x < r; ++x)
                if (t[y][x] == 1) {
                    vector<pair<int,int>> shp;
                    dfs(y, x, 1, t, shp, y, x);
                    normalize(shp);
                    blocks.push_back(shp);
                }
    }
    used.assign(blocks.size(), 0);

    int answer = 0;
    vector<vector<int>> board(game_board);

    for (int y = 0; y < r; ++y)
        for (int x = 0; x < r; ++x)
            if (board[y][x] == 0) {
                vector<pair<int,int>> hole;
                dfs(y, x, 0, board, hole, y, x);
                normalize(hole);

                bool filled = false;       
                for (size_t i = 0; i < blocks.size() && !filled; ++i) {
                    if (used[i] || blocks[i].size() != hole.size()) continue;

                    vector<pair<int,int>> shape = blocks[i];
                    for (int rot = 0; rot < 4 && !filled; ++rot) {
                        if (shape == hole) {
                            used[i] = 1;
                            answer += (int)hole.size();
                            filled = true;  
                        } else {
                            shape = rot90(shape);
                        }
                    }
                }
            }

    return answer;
}
