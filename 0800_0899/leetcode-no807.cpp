#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> column;
        vector<int> row(m);
        for (auto eachline : grid){
            column.push_back(*max_element(eachline.begin(), eachline.end()));
            auto start = &row[0];
            for (auto &t : eachline){
                 *start = max(t,*start);
                 start++;
            }
        }
        for (auto t : column) cout << t << " " ;
        cout << endl;
        for (auto t : row) cout << t << " " ;
        cout << endl;
        int ans = 0;
        for (int i = 0;i < n;++i){
            for (int j = 0;j < m;++j){
                ans += min(column[i],row[j]) - grid[i][j];
            }
        }
        return ans;
    }
};

int main(){
    Solution test;
    vector<vector<int>> eg1 ={{3,0,8,4},{2,4,5,7},{9,2,6,3},{0,3,1,0}};
    cout << test.maxIncreaseKeepingSkyline(eg1) << endl;
    vector<vector<int>> eg2 ={{0,0,0},{0,0,0},{0,0,0}};
    cout << test.maxIncreaseKeepingSkyline(eg2) << endl;
}



//
// Created by ASUS on 2023/9/8.
//
