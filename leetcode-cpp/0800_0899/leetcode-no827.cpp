// problem: https://leetcode.cn/problems/making-a-large-island/?envType=problem-list-v2&envId=3rBpGyas
#include <algorithm>
#include <iostream>
#include <ranges>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution2 {
public:
    // ok but too slow . TLE
    int largestIsland(vector<vector<int>> &grid) {
        int n = grid.size();
        unordered_map<int, int> groupSize;
        auto noVis = grid;
        vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        vector whichGroup(n, vector<int>(n));
        int index = 0;
        vector expandFrom(n, vector(n, vector<int>()));
        vector expanded(n, vector<int>(n));
        const auto dfs = [&](this auto &&dfs, int x, int y) -> void {
            whichGroup[x][y] = index;
            groupSize[index]++;
            noVis[x][y] = 0;
            for (int i = 0; i < 4; ++i) {
                auto [dx, dy] = dirs[i];
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 and nx < n and ny < n and ny >= 0) {
                    if (grid[nx][ny] == 1 and noVis[nx][ny] == 1) {
                        dfs(nx, ny);
                    } else {
                        if (not expanded[nx][ny]) {
                            expandFrom[nx][ny].push_back(index);
                            expanded[nx][ny] = 1;
                        }
                    }
                }
            }
        };
        auto dummy = vector(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (noVis[i][j] == 1) {
                    dfs(i, j);
                    index++;
                    expanded = dummy;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (expandFrom[i][j].size() >= 1) {
                    int temp = 0;
                    for (auto from: expandFrom[i][j]) {
                        temp += groupSize[from];
                    }
                    res = max(temp, res);
                }
            }
        }
        return min(n * n, res + 1);
    }
};


class Solution {
public:
    int largestIsland(vector<vector<int>> &grid) {
        int n = grid.size();
        unordered_map<int, int> groupSize;
        vector noVis = grid;
        vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        vector whichGroup(n, vector<int>(n));
        int index = 0;
        const auto dfs = [&](this auto &&dfs, int x, int y) -> void {
            whichGroup[x][y] = index;
            groupSize[index]++;
            noVis[x][y] = 0;
            for (int i = 0; i < 4; ++i) {
                auto [dx, dy] = dirs[i];
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 and nx < n and ny < n and ny >= 0) {
                    if (grid[nx][ny] == 1 and noVis[nx][ny] == 1) {
                        dfs(nx, ny);
                    }
                }
            }
        };
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (noVis[i][j] == 1) {
                    dfs(i, j);
                    index++;
                }
            }
        }
        int res = 0;
        for (const auto &[k, v]: groupSize) {
            res = max(res, v);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    pmr::unordered_set<int> others;
                    for (int k = 0; k < 4; ++k) {
                        auto [dx, dy] = dirs[k];
                        int nx = i + dx, ny = j + dy;
                        if (nx >= 0 and nx < n and ny < n and ny >= 0 and grid[nx][ny] == 1) {
                            others.insert(whichGroup[nx][ny]);
                        }
                    }
                    int temp = 0;
                    for (auto group: others) {
                        temp += groupSize[group];
                    }
                    res = max(temp, res);
                }
            }
        }
        return min(n * n, res + 1);
    }
};


int main(int argc, char *argv[]) {
    Solution test;
    cout << test.largestIsland(temp_vector({temp_vector({1, 0}), temp_vector({0, 1})})) << endl;
}

//
// Created By jing At 2026-05-04 18:09
//
