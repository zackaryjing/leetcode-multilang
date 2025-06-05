// problem: https://leetcode.cn/problems/unique-paths-iii/
#include <bitset>
#include <iostream>
#include <functional>
#include <set>
#include <unordered_set>
#include <stack>
#include <vector>
#include "../utils/vector_helper.h"
using namespace std;

class Solution {
public:
    int uniquePathsIII(vector<vector<int>> &grid) {
        int startR = 0;
        int startC = 0;
        int endR = 0;
        int endC = 0;
        int n = grid.size();
        int m = grid[0].size();
        int obstacleCnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    startR = i;
                    startC = j;
                } else if (grid[i][j] == 2) {
                    endR = i;
                    endC = j;
                } else if (grid[i][j] == -1) {
                    obstacleCnt += 1;
                }
            }
        }

        int expectedCnt = m * n - obstacleCnt;

        vector<bitset<20>> path(n);
        int pathLength = 0;
        int res = 0;
        function<void(int, int)> dfs = [&](int r, int c) {
            if (r == endR and c == endC) {
                if (pathLength == expectedCnt - 1) {
                    res++;
                } else {
                    return;
                }
            }
            pathLength++;
            path[r].set(c);
            int nxtR = r + 1;
            int nxtC = c;
            if (nxtR < n and not path[nxtR][nxtC] and grid[nxtR][nxtC] >= 0) {
                dfs(nxtR, nxtC);
            }
            nxtR = r - 1;
            nxtC = c;
            if (nxtR >= 0 and not path[nxtR][nxtC] and grid[nxtR][nxtC] >= 0) {
                dfs(nxtR, nxtC);
            }
            nxtR = r;
            nxtC = c + 1;
            if (nxtC < m and not path[nxtR][nxtC] and grid[nxtR][nxtC] >= 0) {
                dfs(nxtR, nxtC);
            }
            nxtR = r;
            nxtC = c - 1;
            if (nxtC >= 0 and not path[nxtR][nxtC] and grid[nxtR][nxtC] >= 0) {
                dfs(nxtR, nxtC);
            }
            path[r].reset(c);
            pathLength--;
        };
        dfs(startR, startC);
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.uniquePathsIII(temp_vector({{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 2}})) << endl;
    cout << test.uniquePathsIII(temp_vector({{1,0,0,0},{0,0,0,0},{0,0,2,-1}})) << endl;
}

//
// Created By Zackary At 2025-06-05 12:16:34
//
