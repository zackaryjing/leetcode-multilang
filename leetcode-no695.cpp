#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int dfs(int i,int j,int n,int m,vector<vector<int>> &grid){
        grid[i][j] = 2;
        vector<vector<int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};
        int total = 0;
        for (auto direction : directions){
            int ni = i + direction[0],nj = j + direction[1];
            if (0 <= ni and ni < n and 0 <= nj and nj < m){
                int s;
                if (grid[ni][nj] == 1){
                    total += dfs(ni,nj,n,m,grid);
                }
            };
        }
        return total + 1;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        int ans = 0;
        for (int i = 0;i < n;i++){
            for (int j = 0;j < m;j++){
                if (grid[i][j] == 1){
                    int res = dfs(i,j,n,m,grid);
//                    cout << res << " " << i << " " << j << endl;
                    if (res > ans){
                        ans = res;
                    }
                }
            }
        }
        return ans;
    }
};
int main(){
    Solution test;
    vector<vector<int>> eg1 =  {{0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},{0,1,0,0,1,1,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}};
    cout << test.maxAreaOfIsland(eg1) << endl;
}
//
// Created by ASUS on 2023/7/11.
//
