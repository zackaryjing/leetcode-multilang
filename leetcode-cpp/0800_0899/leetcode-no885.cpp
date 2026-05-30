// problem: https://leetcode.cn/problems/spiral-matrix-iii/?envType=problem-list-v2&envId=3rBpGyas
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;


class Solution2 {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int realCnts = cols * rows;
        rows += 2, cols += 2, ++rStart, ++cStart;
        vector vis(rows, vector<bool>(cols));
        const vector<vector<int>> direction = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        const vector<vector<int>> right = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int r = rStart, c = cStart;
        vector<vector<int>> res;
        int cur = 0;
        for (int i = 0; i < realCnts;) {
            if (r != 0 and c != 0 and r != rows - 1 and c != cols - 1) {
                res.push_back({r - 1, c - 1});
                ++i;
                vis[r][c] = true;
            }
            int dr = right[cur][0], dc = right[cur][1];
            if (not vis[r + dr][c + dc]) {
                cur = (cur + 1) % 4;
            }
            r += direction[cur][0];
            c += direction[cur][1];
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int realCnts = cols * rows;
        rows += 2, cols += 2, ++rStart, ++cStart;
        vector vis(rows, vector<bool>(cols));
        const vector<vector<int>> direction = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        const vector<vector<int>> right = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int r = rStart, c = cStart;
        vector<vector<int>> res;
        int cur = 0;
        vector length = {1, 1};
        int clength = 0;
        for (int i = 0; i < realCnts;) {
            if (r != 0 and c != 0 and r != rows - 1 and c != cols - 1) {
                res.push_back({r - 1, c - 1});
                ++i;
                vis[r][c] = true;
                ++clength;
            }
            int dr = right[cur][0], dc = right[cur][1];
            if (not vis[r + dr][c + dc]) {
                cur = (cur + 1) % 4;
                length[not(cur & 1)] = max(clength, length[not(cur & 1)]);
                clength = 0;
            }
            if ((r == 0 or r == rows - 1) and (cur & 1) or ((c == 0 or c == cols - 1) and not(cur & 1))) {
                r += direction[cur][0] * length[cur & 1];
                c += direction[cur][1] * length[cur & 1];
                dr = right[cur][0], dc = right[cur][1];
                while (vis[r + dr][c + dc]) {
                    r += direction[cur][0];
                    c += direction[cur][1];
                }
            } else {
                r += direction[cur][0];
                c += direction[cur][1];
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    show_matrix(test.spiralMatrixIII(1, 4, 0, 0));
    show_matrix(test.spiralMatrixIII(5, 6, 1, 4));
    show_matrix(test.spiralMatrixIII(3, 3, 2, 2));
}

//
// Created By jing At 2026-05-30 17:43
//
