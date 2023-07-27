#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};
    vector<vector<int>> dataGrid;
    set<vector<int>> vis;
    int toColor,target,n,m;
    void dfs(int row,int col,vector<vector<int>>& grid){
//        cout << row << " " << col << endl;
        int ways = 0;
        for (auto dir : directions){
            int ni = row + dir[0],nj = col + dir[1];
//            cout << " " << ni << " " << nj << " -- " << (dataGrid[ni][nj] == target) << " - " << (vis.find({ni,nj}) == vis.end()) << " " << endl;//<< vis.find({ni,nj}) << endl;
//            cout << "start " ;
//            for (auto k : vis) cout << k[0] << " " << k[1] << " ";
//            cout << " end" << endl;
            if (ni >= 0 and ni < n and nj >= 0 and nj < m and dataGrid[ni][nj] == target){
                if (vis.find({ni,nj}) == vis.end()){
                    vis.insert({ni,nj});
                    dfs(ni,nj,grid);
                }
            } else {
                ways = 1;
            }
        }
        if (ways == 1){
//            cout << "yes " << toColor << " " << row  << " " << col << " " << ways << endl;
            grid[row][col] = toColor;
        }
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        toColor = color;
        target = grid[row][col];
//        cout << target << endl;
        dataGrid = grid;
        n = grid.size();
        m = grid[0].size();
        dfs(row,col,grid);
        return grid;
    }
};

int main(){
    Solution test;
//    vector<vector<int>> eg1 = {{1,2,2},{2,3,2}};
    vector<vector<int>> eg2 = {{1,1,1},{1,1,1},{1,1,1}};
    auto res = test.colorBorder(eg2,0,1,3);
    for (auto& h : res) {
        for (auto& k : h) {
            cout << k << " " ;
        }
        cout << endl;
    }
}

//
// Created by ASUS on 2023/7/18.
//
