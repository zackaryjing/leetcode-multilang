// problem: https://leetcode.cn/problems/difference-of-number-of-distinct-values-on-diagonals/?envType=daily-question&envId=2025-03-25
#include <iostream>
#include <unordered_set>
#include <vector>
#include "../utils/vector_helper.h"

using namespace std;

class Solution {
public:
    vector<vector<int> > differenceOfDistinctValues(vector<vector<int> > &grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector ans(n, vector(m, 0));
        for (int i = 0; i < m; i++) {
            unordered_set<int> nums;
            vector<int> cnts = {0};
            int j = 0;
            for (; j < n and i + j < m; j++) {
                nums.insert(grid[j][i + j]);
                cnts.push_back(static_cast<int>(nums.size()));
            }
            nums.clear();
            j--;
            for (; j >= 0; j--) {
                ans[j][i + j] = abs(static_cast<int>(nums.size()) - cnts[j]);
                nums.insert(grid[j][i + j]);
            }
        }
        for (int j = 1; j < n; j++) {
            unordered_set<int> nums;
            vector<int> cnts = {0};
            int i = 0;
            for (; i + j < n and i < m; i++) {
                nums.insert(grid[j + i][i]);
                cnts.push_back(static_cast<int>(nums.size()));
            }
            nums.clear();
            i--;
            for (; i >= 0; i--) {
                ans[j + i][i] = abs(static_cast<int>(nums.size()) - cnts[i]);
                nums.insert(grid[j + i][i]);
            }
        }
        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    vector<vector<int> > eg1 = {{1, 2, 3}, {3, 1, 5}, {3, 2, 1}};
    show_matrix(test.differenceOfDistinctValues(eg1));
}

//
// Created by ASUS on 2025/3/25.
//
