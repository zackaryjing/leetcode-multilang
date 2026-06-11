// problem: https://leetcode.cn/problems/map-of-highest-peak/description/?envType=problem-list-v2&envId=OOhHf3Bc
#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        vector res(n, vector<int>(m));
        vector vis(n, vector<bool>(m));
        queue<unsigned int> toVis;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (isWater[i][j]) {
                    toVis.push((i << 16) + j);
                }
            }
        }
        const unsigned int mask = (1 << 16) - 1;
        const vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int index = 1;
        while (not toVis.empty()) {
            int s = toVis.size();
            for (int i = 0; i < s; ++i) {
                int cur = toVis.front();
                toVis.pop();
                uint32_t x = cur >> 16;
                uint32_t y = cur & mask;
                for (const auto &[dx, dy]: dirs) {
                    if (const int nx = x + dx, ny = y + dy;
                        0 <= nx and nx < n and 0 <= ny and ny < m and not(isWater[nx][ny] or vis[nx][ny])) {
                        toVis.push((nx << 16) | ny);
                        res[nx][ny] = index;
                        vis[nx][ny] = true;
                    }
                }
            }
            index++;
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    show_matrix(
    test.highestPeak(temp_vector({temp_vector({0, 0, 1}), temp_vector({1, 0, 0}), temp_vector({0, 0, 0})})));
}

//
// Created By jing At 2026-06-11 20:15
//
