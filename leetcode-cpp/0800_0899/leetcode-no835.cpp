// problem: https://leetcode.cn/problems/image-overlap/?envType=problem-list-v2&envId=3rBpGyas
#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution2 {
public:
    int largestOverlap(vector<vector<int>> &img1, vector<vector<int>> &img2) {
        int n = img1.size();
        vector<unsigned int> im1(n);
        vector<unsigned int> im2(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                im1[i] |= img1[i][j] << j;
                im2[i] |= img2[i][j] << j;
            }
        }
        const unsigned int mask = (1 << n) - 1;
        int res = 0;
        for (int offsetX = -n + 1; offsetX < n; ++offsetX) {
            for (int offsetY = -n + 1; offsetY < n; ++offsetY) {
                int yStart = max(offsetY, 0);
                int yEnd = min(n, n + offsetY);
                int cnt = 0;
                for (int i = yStart; i < yEnd; ++i) {
                    cnt += popcount((offsetX > 0 ? im1[i] << offsetX : im1[i] >> -offsetX) & mask & im2[i - offsetY]);
                }
                res = max(cnt, res);
            }
        }
        return res;
    }
};

class Solution {
public:
    int largestOverlap(vector<vector<int>> &img1, vector<vector<int>> &img2) {
        int n = img1.size();
        vector<unsigned int> im1(n), im2(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                im1[i] |= img1[i][j] << j;
                im2[i] |= img2[i][j] << j;
            }
        }
        const unsigned int mask = (1 << n) - 1;
        int res = 0;
        for (int dx = -n + 1; dx < n; ++dx) {
            for (int dy = -n + 1; dy < n; ++dy) {
                int cnt = 0;
                for (int i = max(dy, 0); i < min(n, n + dy); ++i) {
                    cnt += popcount((dx > 0 ? im1[i] << dx : im1[i] >> -dx) & mask & im2[i - dy]);
                }
                res = max(cnt, res);
            }
        }
        return res;
    }
};


int main(int argc, char *argv[]) {
    Solution test;
    cout << test.largestOverlap(temp_vector<vector<int>>({{1}}), temp_vector<vector<int>>({{1}})) << endl;
    cout << test.largestOverlap(temp_vector<vector<int>>({{0}}), temp_vector<vector<int>>({{0}})) << endl;
    cout << test.largestOverlap(temp_vector({{1, 1, 0}, {0, 1, 0}, {0, 1, 0}}),
                                temp_vector({{0, 0, 0}, {0, 1, 1}, {0, 0, 1}}))
         << endl;
}

//
// Created By jing At 2025-10-26 15:51
//
