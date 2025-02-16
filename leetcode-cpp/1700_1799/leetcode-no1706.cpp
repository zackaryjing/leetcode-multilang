#include <iostream>
#include <vector>
#include "../utils/vector_helper.h"

using namespace std;

class Solution {
public:
    vector<int> findBall(vector<vector<int> > &grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> ans(m);
        for (int i = 0; i < m; ++i) {
            int curx = i;
            bool valid = true;
            for (int j = 0; j < n; j++) {
                if (grid[j][curx] == 1 and curx < m - 1 and grid[j][curx + 1] == 1) {
                    curx++;
                } else if (grid[j][curx] == -1 and curx > 0 and grid[j][curx - 1] == -1) {
                    curx--;
                } else {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                ans[i] = curx;
            } else {
                ans[i] = -1;
            }
        }
        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    vector<vector<int> > eg1 = {
        {1, 1, 1, -1, -1}, {1, 1, 1, -1, -1}, {-1, -1, -1, 1, 1}, {1, 1, 1, 1, -1}, {-1, -1, -1, -1, -1}
    };
    vector<vector<int> > eg2 = {
        {1, 1, 1, 1, 1, 1}, {-1, -1, -1, -1, -1, -1}, {1, 1, 1, 1, 1, 1}, {-1, -1, -1, -1, -1, -1}
    };
    vector<vector<int> > eg3 = {
        {
            -1, 1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, 1, 1, -1, -1, -1, 1, 1, 1, -1, -1, 1, 1, -1, -1, 1, -1,
            -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, 1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, 1, -1, 1, -1, -1, 1, 1, -1,
            1, -1, -1, -1, -1, 1, 1, 1, 1, 1, 1, -1, 1, 1, 1, -1, 1, 1, 1, -1, -1, -1, 1, -1, 1, -1, -1, 1, 1, -1, -1,
            1, -1, 1, -1, 1, 1, 1, -1, -1, -1, -1
        }
    };
    vector<int> res = test.findBall(eg3);
    show_vector(res);
}


//
// Created by ASUS on 2025/2/15.
//
