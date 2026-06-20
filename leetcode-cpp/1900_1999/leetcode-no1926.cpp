// problem: https://leetcode.cn/problems/nearest-exit-from-entrance-in-maze/?envType=problem-list-v2&envId=3rBpGyas
#include <algorithm>
#include <deque>
#include <iostream>
#include <ranges>
#include <unordered_set>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance) {
        deque<long long> toExplore;
        const int n = maze.size(), m = maze[0].size();
        vector vis(n, vector<bool>(m));
        const long long mask = (1LL << 32) - 1;
        const vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int index = 0;
        long long start = (static_cast<long long>(entrance[0]) << 32) + entrance[1];
        toExplore.push_back(start);
        vis[entrance[0]][entrance[1]] = true;
        while (not toExplore.empty()) {
            int s = toExplore.size();
            for (int i = 0; i < s; ++i) {
                auto cur = toExplore.front();
                toExplore.pop_front();
                const int x = cur >> 32, y = cur & mask;
                for (const auto &[dx, dy]: dirs) {
                    const int nx = x + dx, ny = y + dy;
                    if (const long long nxt = ((long long) nx << 32) + ny; 0 <= nx and nx < n and 0 <= ny and ny < m) {
                        if (not vis[nx][ny] and maze[nx][ny] == '.') {
                            vis[nx][ny] = true;
                            toExplore.push_back(nxt);
                            if (nx == 0 or nx == n - 1 or ny == 0 or ny == m - 1) {
                                return index + 1;
                            }
                        }
                    }
                }
            }
            index++;
        }
        return -1;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.nearestExit(temp_vector({temp_vector({'+', '+', '.', '+'}), temp_vector({'.', '.', '.', '+'}),
                                          temp_vector({'+', '+', '+', '.'})}),
                             temp_vector({1, 2}))
         << endl;
    cout << test.nearestExit(
            temp_vector({temp_vector({'+', '+', '+'}), temp_vector({'.', '.', '.'}), temp_vector({'+', '+', '+'})}),
            temp_vector({1, 0}))
         << endl;
}

//
// Created By jing At 2026-06-09 14:50
//
