#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        int ans = 0;
        for (int i = 1;i < n - 1;i++){
            for (int j = 1;j < m - 1;j++){
                if (grid[i][j] != 5) continue;
                vector<vector<vector<int>>> checks = {{{-1,-1},{-1,0},{-1,1}},
                                                      {{0,-1},{0,0},{0,1}},
                                                      {{1,-1},{1,0},{1,1}},
                                                      {{-1,-1},{0,-1},{1,-1}},
                                                      {{-1,0},{0,0},{1,0}},
                                                      {{-1,1},{0,1},{1,1}},
                                                      {{-1,-1},{0,0},{1,1}},
                                                      {{-1,1},{0,0},{1,-1}}};
                unordered_map<int,int> uni;
                for (int k = 0;k < 3;k++){
                    vector<vector<int>>line = checks[k];
                    for (auto each : line){
                        uni[grid[i+each[0]][j+each[1]]]++;
                    }
                }
                int invalid = 0;
                for (int h = 1;h <= 9;h++){
                    if (uni[h] != 1){
//                        cout << " * " << endl;
                        invalid = 1;
                        break;
                    }
                }
                if (invalid) continue;
                for (auto& check : checks){
                    int total = 0;
                    for (auto pos : check){
                        total += grid[pos[0]+i][pos[1]+j];
                    }
                    if (total != 15){
                        invalid = 1;
                        break;
                    }
                }
                if (invalid) continue;
                ans ++;
            }
        }
        return ans;
    }
};

int main(){
    Solution test;
//    vector<vector<int>> eg1 = {{4,3,8,4},{9,5,1,9},{2,7,6,2}};
//    cout << test.numMagicSquaresInside(eg1) << endl;
    vector<vector<int>> eg2 = {{8,0,7,4,3,2},
                               {1,10,4,4,3,8},
                               {8,5,2,9,5,1},
                               {6,0,9,2,7,6},
                               {9,0,6,9,5,1},
                               {4,2,1,4,3,8}};
    cout << test.numMagicSquaresInside(eg2) << endl;


}


//
// Created by ASUS on 2023/7/11.
//
