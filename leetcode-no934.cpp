#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution2 {
public:
    vector<vector<int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};
    void dfs(int i,int j,const vector<vector<int>>& grid,
             vector<vector<int>> &vis,vector<vector<int>>& border,int n,int m){
        int inland =  0;
        vis.push_back({i,j});
//        cout << i << " " << j << " -> ";
        for (auto direction : directions){
            if (i + direction[0] < n and 0 <= (i + direction[0]) and
            j + direction[1] < m and 0 <= (j + direction[1]) and
            grid[i+direction[0]][j+direction[1]] == 1){
                inland ++;
                vector<int> tmp = {i+direction[0],j+direction[1]};
                if (find(vis.begin(),vis.end(),tmp) == vis.end()){
//                    cout << "(" << (find(vis.begin(),vis.end(),tmp) == vis.end()) << ")";
                    dfs(i+direction[0],j+direction[1],grid,vis,border,n,m);
                }
            }
        }
//        cout << i << " " << j << " " << inland << endl;
        if (inland != 4){
            border.push_back({i,j});
        }
    }
    int bfs(vector<vector<int>>& border,vector<vector<int>>& vis,int lvl,vector<vector<int>>&grid,int n,int m) {
        while (true){
            vector<vector<int>> newborder;
            int found = 0;
            for (auto stone : border){
                for (auto direction : directions){
                    if (stone[0] + direction[0] < n and 0 <= (stone[0] + direction[0]) and
                        stone[1] + direction[1] < m and 0 <= (stone[1] + direction[1])) {
                        vector<int> tmp = {stone[0]+direction[0],stone[1] + direction[1]};
                        if (find(vis.begin(),vis.end(),tmp) == vis.end()){
                            vis.push_back(tmp);
                            newborder.push_back(tmp);
                            if (grid[stone[0]+direction[0]][stone[1]+direction[1]] == 1) {
                                found = 1;
                                break;
                            }
                        }
                    }
                }
                if (found) {
                    break;
                }
            }
            if (found){
                break;
            }
            border = newborder;
            lvl ++;
        }
        return lvl;
    }

    int shortestBridge(vector<vector<int>>& grid) {
        vector<vector<int>> data;
        int n = grid.size();
        int m =  grid[0].size();
        vector<vector<int>> vis,border;
        for (int i = 0;i<n;i++){
            int found = 0;
            for (int j = 0;j<m;j++){
//                cout << i << " " << j << endl;
                vector<int> tmp = {i,j};
                if (grid[i][j] == 1){
                    dfs(i,j,grid,vis,border,n,m);
                    found = 1;
                    break;
                }
            }
            if (found){
                break;
            }
        }

//        cout << bfs(border,vis,0,grid,n,m) << " +++ " << endl;
//
//        cout << border.size() << endl;
//        for (auto stone : border){
//            cout << stone[0] << " " << stone[1] << endl;
//        }
//        cout << endl;
//        cout << vis.size() << endl;
//        for (auto stone : vis){
//            cout << stone[0] << " " << stone[1] << endl;
//        }
//
//        cout << string(30,'-') << endl;
        return bfs(border,vis,0,grid,n,m);
    }
};

class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dirs = {{-1,0},{1,0},{0,1},{0,-1}};
        vector<pair<int,int>> island;
        queue<pair<int,int>> qu;

        for (int i = 0;i < n;i++){
            for (int j = 0;j < n;j++){
                if (grid[i][j] == 1){
                    qu.emplace(i,j);
                    grid[i][j] = -1;
                    while (!qu.empty()){
                        auto [x,y] = qu.front();
                        qu.pop();
                        island.emplace_back(x,y);
                        for (int k = 0;k < 4;k++){
                            int nx = x + dirs[k][0];
                            int ny = y + dirs[k][1];
                            if (nx > 0 and ny >= 0 and nx < n and ny < n and grid[nx][ny] == 1){
                                qu.emplace(nx,ny);
                                grid[nx][ny] = -1;
                            }
                        }
                    }
                    for (auto &&[x,y] : island){
                        qu.emplace(x,y);
                    }
                    int step = 0;
                    while (!qu.empty()){
                        int sz = qu.size();
                        for (int i = 0;i <sz;i++){
                            auto [x,y] = qu.front();
                            qu.pop();
                            for (int k = 0;k < 4;k++){
                                int nx = x + dirs[k][0];
                                int ny = y + dirs[k][1];
                                if (nx >= 0 and ny >= 0 and nx < n and ny < n){
                                    if (grid[nx][ny] == 0){
                                        qu.emplace(nx,ny);
                                        grid[nx][ny] = -1;
                                    } else if (grid[nx][ny] == 1){
                                        qu.emplace(nx,ny);
                                        grid[nx][ny] = -1;
                                    } else if(grid[nx][ny] == 1){
                                        return step;
                                    }
                                }
                            }
                        }
                        step ++;
                    }
                }
            }
        }
        return 0;
    }
};

int main(){
    Solution test;
    vector<vector<int>> eg1 = {{1,1,1,1,1},{1,0,0,0,1},{1,0,1,0,1},{1,0,0,0,1},{1,1,1,1,1}};
    cout << test.shortestBridge(eg1) << endl;
    cout << endl;
    vector<vector<int>> eg2 = {{0,1,0},{0,0,0},{0,0,1}};
    cout << test.shortestBridge(eg2) << endl;
    vector<vector<int>> eg3 = {{0,1},{1,0}};
    cout << test.shortestBridge(eg3) << endl;
}

//
// Created by ASUS on 2023/7/9.
//
