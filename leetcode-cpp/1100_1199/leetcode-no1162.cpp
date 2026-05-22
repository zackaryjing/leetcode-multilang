// problem: https://leetcode.cn/problems/as-far-from-land-as-possible/?envType=problem-list-v2&envId=OOhHf3Bc
#include <algorithm>
#include <iostream>
#include <queue>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution2 {
public:
    int maxDistance(vector<vector<int>> &grid) {
        const int n = grid.size();
        queue<pair<int, int>> toVis;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    toVis.emplace(i, j);
                }
            }
        }
        if (toVis.size() == n * n) return -1;
        int index = 0;
        const vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while (toVis.size() > 0) {
            // cout << "toVis.size(): " << toVis.size() << endl;
            int size = toVis.size();
            for (int i = 0; i < size; ++i) {
                auto [ci, cj] = toVis.front();
                toVis.pop();
                for (auto &[di, dj]: dirs) {
                    int ni = ci + di, nj = cj + dj;
                    if (0 <= ni and ni < n and 0 <= nj and nj < n and not grid[ni][nj]) {
                        toVis.emplace(ni, nj);
                        grid[ni][nj] = 1;
                    }
                }
            }
            index++;
        }
        return index - 1;
    }
};


class Solution {
public:
    int maxDistance(vector<vector<int>> &grid) {
        const int n = grid.size();
        queue<int> toVis;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j]) toVis.push(i * 1000 + j);
        if (toVis.size() == n * n) return -1;
        int index = 0;
        const vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while (toVis.size() > 0) {
            int size = toVis.size();
            for (int i = 0; i < size; ++i) {
                const int cj = toVis.front() % 1000, ci = toVis.front() / 1000;
                toVis.pop();
                for (const auto &[di, dj]: dirs)
                    if (int ni = ci + di, nj = cj + dj; 0 <= ni and ni < n and 0 <= nj and nj < n and not grid[ni][nj])
                        toVis.push(ni * 1000 + nj), grid[ni][nj] = 1;
            }
            index++;
        }
        return index - 1;
    }
};


int main(int argc, char *argv[]) {
    Solution test;
    cout << test.maxDistance(temp_vector({temp_vector({1, 0, 1}), temp_vector({0, 0, 0}), temp_vector({1, 0, 1})}))
         << endl;
    cout << test.maxDistance(temp_vector({temp_vector({1, 0, 0}), temp_vector({0, 0, 0}), temp_vector({0, 0, 0})}))
         << endl;
    cout << test.maxDistance(
            temp_vector({temp_vector({1, 0, 0, 0, 0, 1, 0, 0, 0, 1}), temp_vector({1, 1, 0, 1, 1, 1, 0, 1, 1, 0}),
                         temp_vector({0, 1, 1, 0, 1, 0, 0, 1, 0, 0}), temp_vector({1, 0, 1, 0, 1, 0, 0, 0, 0, 0}),
                         temp_vector({0, 1, 0, 0, 0, 1, 1, 0, 1, 1}), temp_vector({0, 0, 1, 0, 0, 1, 0, 1, 0, 1}),
                         temp_vector({0, 0, 0, 1, 1, 1, 1, 0, 0, 1}), temp_vector({0, 1, 0, 0, 1, 0, 0, 1, 0, 0}),
                         temp_vector({0, 0, 0, 0, 0, 1, 1, 1, 0, 0}), temp_vector({1, 1, 0, 1, 1, 1, 1, 1, 0, 0})}))
         << endl;
}

//
// Created By jing At 2026-05-22 22:13
//
