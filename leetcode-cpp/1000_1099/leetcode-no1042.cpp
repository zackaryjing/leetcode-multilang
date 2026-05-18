// problem: https://leetcode.cn/problems/flower-planting-with-no-adjacent/?envType=problem-list-v2&envId=OOhHf3Bc
#include <algorithm>
#include <deque>
#include <filesystem>
#include <iostream>
#include <queue>
#include <ranges>
#include <unordered_set>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution2 {
    // work but TLE
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>> &paths) {
        vector connected(n + 1, vector<bool>(n + 1));
        vector graph(n + 1, vector<int>());
        for (int i = 0; i < paths.size(); ++i) {
            const auto &path = paths[i];
            graph[path[0]].push_back(path[1]);
            graph[path[1]].push_back(path[0]);
            connected[path[0]][path[1]] = true;
            connected[path[1]][path[0]] = true;
        }
        queue<int> dq;
        vector<int> color(n);
        auto index = views::iota(1, n + 1);
        unordered_set all(index.begin(), index.end());
        while (not all.empty()) {
            dq.push(*all.begin());
            while (not dq.empty()) {
                int cur = dq.front();
                dq.pop();
                all.erase(cur);
                unordered_set colors = {1, 2, 3, 4};
                for (auto ng: graph[cur]) {
                    if (not color[ng - 1]) {
                        dq.push(ng);
                    }
                    if (connected[cur][ng]) {
                        colors.erase(color[ng - 1]);
                    }
                }
                color[cur - 1] = *colors.begin();
            }
        }
        return color;
    }
};


class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>> &paths) {
        vector graph(n + 1, vector<int>());
        for (const auto &path: paths) {
            graph[path[0]].push_back(path[1]);
            graph[path[1]].push_back(path[0]);
        }
        vector<int> color(n);
        for (int i = 0; i < n; ++i) {
            vector<bool> colored(5, false);
            for (const auto ng: graph[i + 1]) {
                colored[color[ng - 1]] = true;
            }
            for (int j = 1; j < 5; ++j) {
                if (not colored[j]) {
                    color[i] = j;
                    break;
                }
            }
        }
        return color;
    }
};


int main(int argc, char *argv[]) {
    Solution test;
    show_vector(test.gardenNoAdj(3, temp_vector({temp_vector({1, 2}), temp_vector({2, 3}), temp_vector({3, 1})})));
}

//
// Created By jing At 2026-05-18 18:22
//
