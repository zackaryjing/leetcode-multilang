// problem:
// https://leetcode.cn/problems/path-with-maximum-probability/description/?envType=problem-list-v2&envId=OOhHf3Bc
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
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> graph(n);
        vector<bool> vis(n);
        for (int i = 0; i < edges.size(); ++i) {
            const auto &edge = edges[i];
            graph[edge[0]].emplace_back(edge[1], succProb[i]);
            graph[edge[1]].emplace_back(edge[0], succProb[i]);
        }
        double res = 0.0;
        priority_queue<pair<double, int>> toVis;
        toVis.emplace(1., start_node);
        while (not toVis.empty()) {
            auto [cp, cur] = toVis.top();
            toVis.pop();
            if (vis[cur]) continue;
            if (cur == end_node) break;
            vis[cur] = true;
            bool found = false;
            for (auto &[child, p]: graph[cur]) {
                if (not vis[child]) {
                    if (child == end_node) res = max(p * cp, res);
                    toVis.emplace(p * cp, child);
                }
            }
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    cout << test.maxProbability(3, temp_vector({temp_vector({0, 1}), temp_vector({1, 2}), temp_vector({0, 2})}),
                                temp_vector({0.5, 0.5, 0.2}), 0, 2)
         << endl;
}

//
// Created By jing At 2026-06-09 20:35
//
