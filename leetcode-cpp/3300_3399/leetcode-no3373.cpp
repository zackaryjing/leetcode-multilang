// problem: https://leetcode.cn/problems/maximize-the-number-of-target-nodes-after-connecting-trees-ii/?envType=daily-question&envId=2025-05-29
#include <deque>
#include <iostream>
#include <vector>

#include "../utils/vector_helper.h"


using namespace std;


class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>> &edges1, vector<vector<int>> &edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        vector<vector<int>> graph1(n);
        for (auto edge: edges1) {
            graph1[edge[0]].push_back(edge[1]);
            graph1[edge[1]].push_back(edge[0]);
        }
        vector<vector<int>> graph2(m);
        for (auto edge: edges2) {
            graph2[edge[0]].push_back(edge[1]);
            graph2[edge[1]].push_back(edge[0]);
        }
        vector<int> colors1(n);
        vector<int> colors2(m);
        colors1[0] = 1;
        deque<int> queue1;
        queue1.push_back(0);
        vector<int> cnt1 = {1, 0};
        while (not queue1.empty()) {
            auto head = queue1.front();
            auto cur_color = colors1[head];
            queue1.pop_front();
            for (auto child: graph1[head]) {
                if (not colors1[child]) {
                    colors1[child] = not(cur_color - 1) + 1;
                    cnt1[colors1[child] - 1]++;
                    queue1.push_back(child);
                }
            }
        }

        colors2[0] = 1;
        deque<int> queue2;
        queue2.push_back(0);
        vector<int> cnt2 = {1, 0};
        while (not queue2.empty()) {
            auto head = queue2.front();
            auto cur_color = colors2[head];
            queue2.pop_front();
            for (auto child: graph2[head]) {
                if (not colors2[child]) {
                    colors2[child] = not(cur_color - 1) + 1;
                    cnt2[colors2[child] - 1]++;
                    queue2.push_back(child);
                }
            }
        }
        vector<int> res(n);
        auto max_other = max(cnt2[1], cnt2[0]);
        for (int i = 0; i < n; ++i) {
            auto c = colors1[i] - 1;
            res[i] = cnt1[c] + max_other;
        }
        return res;
    }
};


class Solution2 {
    // 性能一般，觉得是闭包+返回了不必要的值导致的.
public:
    vector<int> maxTargetNodes(vector<vector<int>> &edges1, vector<vector<int>> &edges2) {
        auto getCnt = [](vector<vector<int>> &edges) {
            int n = edges.size() + 1;
            vector<vector<int>> graph(n);
            for (auto edge: edges) {
                graph[edge[0]].push_back(edge[1]);
                graph[edge[1]].push_back(edge[0]);
            }
            vector<int> colors(n);
            colors[0] = 1;
            deque<int> queue;
            queue.push_back(0);
            vector<int> cnt = {1, 0};
            while (not queue.empty()) {
                auto head = queue.front();
                auto cur_color = colors[head];
                queue.pop_front();
                for (auto child: graph[head]) {
                    if (not colors[child]) {
                        colors[child] = not(cur_color - 1) + 1;
                        cnt[colors[child] - 1]++;
                        queue.push_back(child);
                    }
                }
            }
            // show_vector(cnt);
            // show_vector(colors);
            return pair(cnt, colors);
        };
        auto [cnt1,colors1] = getCnt(edges1);
        auto [cnt2,colors2] = getCnt(edges2);
        auto n = edges1.size() + 1;
        vector<int> res(n);
        auto max_other = max(cnt2[1], cnt2[0]);
        for (int i = 0; i < n; ++i) {
            auto c = colors1[i] - 1;
            res[i] = cnt1[c] + max_other;
        }
        return res;
    }
};

int main(int argc, char *argv[]) {
    Solution test;
    show_vector(test.maxTargetNodes(temp_vector<vector<int>>({{0, 1}, {0, 2}, {2, 3}, {2, 4}}),
                                    temp_vector<vector<int>>({{0, 1}, {0, 2}, {0, 3}, {2, 7}, {1, 4}, {4, 5},
                                                              {4, 6}})));
    show_vector(test.maxTargetNodes(temp_vector<vector<int>>({{0, 1}, {0, 2}, {0, 3}, {0, 4}}),
                                    temp_vector<vector<int>>({{0, 1}, {1, 2}, {2, 3}})));
}

//
// Created By Zackary At 2025-05-29 20:44:35
//
