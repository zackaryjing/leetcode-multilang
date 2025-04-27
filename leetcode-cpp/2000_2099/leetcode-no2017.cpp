// problem: https://leetcode.cn/problems/grid-game/
#include <iostream>
#include <vector>

#include "../utils/vector_helper.h"
using namespace std;

class Solution {
public:
    long long gridGame(vector<vector<int>> &grid) {
        long long lb = 0;
        long long tr = 0;
        int m = grid[0].size();
        for (int i = 1; i < m; ++i) {
            tr += grid[0][i];
        }

        long long res = max(lb, tr);
        for (int j = 0; j < m - 1; ++j) {
            lb += grid[1][j];
            tr -= grid[0][j + 1];
            res = min(res, max(lb, tr));
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.gridGame(temp_vector<vector<int>>({{2, 5, 4}, {1, 5, 1}})) << endl;
    cout << test.gridGame(temp_vector<vector<int>>({{3, 3, 1}, {8, 5, 2}})) << endl;
    cout << test.gridGame(temp_vector<vector<int>>({{1, 3, 1, 15}, {1, 3, 3, 1}})) << endl;
}

//
// Created By Zackary At 2025-04-26 18:24:00
//
