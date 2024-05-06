#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        for (auto& j : grid){
            if (j[0] == 0){
                for (int i = 0;i < m;i++){
                    j[i] = !j[i];
                }
            }
        }
        for (int k = 0;k < m;++k){
            int zerotimes = 0;
            for (int t = 0;t < n;++t){
                if (grid[t][k] == 0){
                    zerotimes += 1;
                }
            }
            if (zerotimes > n / 2){
                for (int j = 0;j < n;++j){
                    grid[j][k] = !grid[j][k];
                }
            }
        }
        for (int i = 0;i < n;++i){
            for (int j = 0;j < m;++j){
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
        int total = 0;
        for (int t = 0;t < n;++t){
            int tmp = 0;
            for (int k = 0;k < m;++k){
                tmp <<= 1;
                if (grid[t][k] == 1){
                    tmp++;
                }
            }
//            cout << tmp << " <=> " << endl;
            total += tmp;
        }
        return total;
    }
};

int main(){
    Solution test;
    vector<vector<int>> eg1 = {{0,0,1,1},{1,0,1,0},{1,1,0,0}};
    cout << test.matrixScore(eg1) << endl;
    vector<vector<int>> eg2 = {{0}};
    cout << test.matrixScore(eg2) << endl;
}
//
// Created by ASUS on 2023/9/2.
//
