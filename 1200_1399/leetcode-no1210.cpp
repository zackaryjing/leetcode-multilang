#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
#include <cstring>

using namespace std;

class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        vector<vector<int>> moves = {{1,0,0},{0,1,0},{0,0,1}};
        queue<vector<int>> q({{0,0,0}});
        int step = 0,n = grid.size();
        bool vis[n][n][2]; memset(vis,0,sizeof(vis));
        while (not q.empty()){
            cout << string(30,'-');
            queue<vector<int>> tmp = q;
            q = queue<vector<int>>();
            while (not tmp.empty()){
                cout << tmp.size() << endl;
                const vector<int> data = tmp.front();
                int X = data[0],Y = data[1],S = data[2];
                tmp.pop();
                for (auto move : moves){
                    int x = X + move[0],y = Y + move[1],s = S ^ move[2];
                    int x2 = x + s,y2 = y + (s ^ 1);
                    if (x2 < n && y2 < n and !vis[x][y][s] and
                    grid[x][y] == 0 and grid[x2][y2] and (move[2] == 0 or grid[x + 1][y + 1] == 0)){
                        if (x == n - 1 and y == n - 2) return step;
                        vis[x][y][s] = true;
                        q.push({x,y,s});
                    }
                }
            }
            step ++;
        }
        return -1;
    }
};
//                    int dx = move[0],dy = move[1],ds = move[2] ^ data[2];
//                    if ((X + dx) < n and (Y + dy) < n and grid[X + dx][Y + dy] == 0
//                        and grid[X + dx + ds][Y + dy + (ds ^ 1)] == 0
//                        and (move[2] == 0 or grid[X + 1][Y + 1] == 0)
//                        and (not vis[X + dx][Y + dy][ds])){
//                        if (X + dx == n - 2 and Y + dy == n - 1 and (S^ds) == 0){
//                            return step;
//                        }
//                        cout << " here " << endl;
//                        vis[X + dx][Y + dy][ds] = true;
//                        cout << " there " << endl;
//                        q.push({X + dx,Y + dy,});
//                    }

int main(){
    Solution test;
    cout << "asf" << endl;
    vector<vector<int>> grid = {{0,0,0,0,0,1},
                                {1,1,0,0,1,0},
                                {0,0,0,0,1,1},
                                {0,0,1,0,1,0},
                                {0,1,1,0,0,0},
                                {0,1,1,0,0,0}};
    cout << test.minimumMoves(grid) << endl;
}
//
// Created by ASUS on 2023/7/15.
//
