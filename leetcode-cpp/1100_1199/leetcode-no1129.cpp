// problem: https://leetcode.cn/problems/shortest-path-with-alternating-colors/?envType=problem-list-v2&envId=OOhHf3Bc
#include <algorithm>
#include <deque>
#include <iostream>
#include <ranges>
#include <vector>
#include "../utils/vector_helper.h"


using namespace std;

class Solution {
public:
    int _n;
    vector<vector<pair<int, bool>>> graph;
    vector<int> res;
    void getDis(bool curNeed) {
        deque<int> dq;
        dq.push_back(0);
        vector vis(_n, vector<bool>(2));
        vis[0][not curNeed] = true;
        int dis = 1;
        while (not dq.empty()) {
            int m = dq.size();
            for (int i = 0; i < m; ++i) {
                int cur = dq.front();
                dq.pop_front();
                for (auto &[nx, isRed]: graph[cur]) {
                    if (isRed == curNeed and not vis[nx][curNeed]) {
                        res[nx] = min(dis, res[nx]);
                        dq.push_back(nx);
                        vis[nx][curNeed] = true;
                    }
                }
            }
            curNeed = not curNeed;
            dis++;
        }
    }
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges) {
        _n = n;
        graph.resize(n);
        res = vector<int>(n, INT_MAX);
        res[0] = 0;
        for (const auto edge: redEdges) {
            graph[edge[0]].emplace_back(edge[1], true);
        }
        for (const auto edge: blueEdges) {
            graph[edge[0]].emplace_back(edge[1], false);
        }
        getDis(true);
        getDis(false);
        for (auto &d: res) {
            if (d == INT_MAX) {
                d = -1;
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    show_vector(test.shortestAlternatingPaths(3, temp_vector({temp_vector({0, 1}), temp_vector({1, 2})}),
                                              temp_vector<vector<int>>({})));
    show_vector(test.shortestAlternatingPaths(
    5, temp_vector({temp_vector({0, 1}), temp_vector({1, 2}), temp_vector({2, 3}), temp_vector({3, 4})}),
    temp_vector({temp_vector({1, 2}), temp_vector({2, 3}), temp_vector({3, 1})})));
}

//
// Created By jing At 2026-05-11 21:51
//
